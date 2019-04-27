#include "SplineParser.hpp"

SplineParser SplineParser::parseFile(std::string filePath)
{
    enum parsingState {KIND, CROSSNUM, CTRLPNTNUM, CTRLPNT, SCAL, ROT, POS, CLEAR, END} state = KIND;
    std::ifstream stream(filePath.data());

    SplineParser sp;
    int crossSectionNum;
    int controlPointNumPerCross;
    std::vector<Vector3f> controlPointsV;
    int tempCounter = 0;
    int crossSectionCounter = 0;
    float tempScalingFactor;
    Quaternion tempRotation;
    Vector3f tempPosition;

    if (stream.is_open())
    {
        std::string s;
        while (std::getline(stream, s))
        {
            int commentIndex = s.find_first_of('#');
            if(commentIndex != s.npos)
            {
                s = s.substr(0, commentIndex);
            }
            if(s.size() == 0 || s[0] == ' ')
            {
                continue;
            }
            std::stringstream ss(s);

            if (state == KIND)
            {
                std::string kindString;
                ss >> kindString;
                sp.splineMode = kindString.compare("BSPLINE") == 0 ? BSPLINE : CATMULL_ROM; 
                state = CROSSNUM;
            }
            else if (state == CROSSNUM)
            {
                ss >> crossSectionNum;
                state = CTRLPNTNUM;
            }
            else if (state == CTRLPNTNUM)
            {
                ss >> controlPointNumPerCross;
                sp.controlPointsNum = controlPointNumPerCross;
                state = CTRLPNT;
            }
            else if (state == CTRLPNT)
            {
                float x, z;
                ss >> x >> z;
                controlPointsV.push_back({x, 0, z});
                tempCounter++;
                if(tempCounter >= controlPointNumPerCross)
                {
                    tempCounter = 0;
                    state = SCAL;
                }
            }
            else if (state == SCAL)
            {
                ss >> tempScalingFactor;
                state = ROT;
            }
            else if (state == ROT)
            {
                float angle, x, y, z;
                ss >> angle >> x >> y >> z;
                tempRotation = expToQuat(angle, {x, y, z});
                state = POS;
            }
            else if (state == POS)
            {
                float x, y, z;
                ss >> x >> y >> z;
                tempPosition = {x, y, z};
                state = CLEAR;
            }

            if (state == CLEAR)
            {
                SplineParser::CrossSection newCross;
                newCross.surface = controlPointsV;
                newCross.position = tempPosition;
                newCross.orientation = tempRotation;
                newCross.scale = tempScalingFactor;
                sp.crossSections.push_back(newCross);

                state = CTRLPNT;
                crossSectionCounter++;
                if(crossSectionCounter >= crossSectionNum)
                {
                    break;
                }
            }
        }
        stream.close();
    }
    else
    {
        std::cout << "File not found." << std::endl;
        exit(1);
    }

    return sp;
}

std::shared_ptr<Object> SplineParser::generateObject(int splineLevel)
{
    printf("%d\n", controlPointsNum);
    std::vector<Vector3f> vertices;
    for(int i = 1; i < controlPointsNum - 1; i++)
    {
        vertices.push_back(crossSections[0].surface[0] + crossSections[0].position);
        vertices.push_back(crossSections[0].surface[i] + crossSections[0].position);
        vertices.push_back(crossSections[0].surface[i + 1] + crossSections[0].position);
    }
    for(int i = 0; i < crossSections.size() - 1; i++)
    {
        for(int j = 0; j < controlPointsNum; j++)
        {
            vertices.push_back(crossSections[i].surface[j % controlPointsNum] + crossSections[i].position);
            vertices.push_back(crossSections[i + 1].surface[j % controlPointsNum] + crossSections[i + 1].position);
            vertices.push_back(crossSections[i].surface[(j + 1) % controlPointsNum] + crossSections[i].position);

            vertices.push_back(crossSections[i].surface[(j + 1) % controlPointsNum] + crossSections[i].position);
            vertices.push_back(crossSections[i + 1].surface[j % controlPointsNum] + crossSections[i + 1].position);
            vertices.push_back(crossSections[i + 1].surface[(j + 1) % controlPointsNum] + crossSections[i + 1].position);
        }
    }
    for(int i = 1; i < controlPointsNum - 1; i++)
    {
        vertices.push_back(crossSections[crossSections.size() - 1].position + crossSections[crossSections.size() - 1].surface[0]);
        vertices.push_back(crossSections[crossSections.size() - 1].position + crossSections[crossSections.size() - 1].surface[i]);
        vertices.push_back(crossSections[crossSections.size() - 1].position + crossSections[crossSections.size() - 1].surface[i + 1]);
    }
    std::shared_ptr<Object> result = std::make_shared<Object>(vertices);
    return result;
}