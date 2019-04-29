#include "SplineParser.hpp"

Vector3f SplineParser::CrossSection::getAppliedVertexAt(int index)
{
    Quaternion q = {0, scale * surface[index].x, scale * surface[index].y, scale * surface[index].z};
    q = orientation * q * inverse(orientation);
    return Vector3f{q.x, q.y, q.z} + position;
}

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
    auto generated = getSplinedSections(splineLevel);
    std::vector<Vector3f> vertices;
    for(int i = 1; i < controlPointsNum - 1; i++)
    {
        vertices.push_back(generated[0].getAppliedVertexAt(0));
        vertices.push_back(generated[0].getAppliedVertexAt(i));
        vertices.push_back(generated[0].getAppliedVertexAt(i + 1));
    }
    for(int i = 0; i < generated.size() - 1; i++)
    {
        for(int j = 1; j < controlPointsNum - 1; j++)
        {
            vertices.push_back(generated[i].getAppliedVertexAt(0));
            vertices.push_back(generated[i].getAppliedVertexAt(j));
            vertices.push_back(generated[i].getAppliedVertexAt(j + 1));
        }
        for(int j = 0; j < controlPointsNum; j++)
        {
            vertices.push_back(generated[i].getAppliedVertexAt(j % controlPointsNum));
            vertices.push_back(generated[i + 1].getAppliedVertexAt(j % controlPointsNum));
            vertices.push_back(generated[i].getAppliedVertexAt((j + 1) % controlPointsNum));

            vertices.push_back(generated[i].getAppliedVertexAt((j + 1) % controlPointsNum));
            vertices.push_back(generated[i + 1].getAppliedVertexAt(j % controlPointsNum));
            vertices.push_back(generated[i].getAppliedVertexAt(j % controlPointsNum));

            vertices.push_back(generated[i].getAppliedVertexAt((j + 1) % controlPointsNum));
            vertices.push_back(generated[i + 1].getAppliedVertexAt(j % controlPointsNum));
            vertices.push_back(generated[i + 1].getAppliedVertexAt((j + 1) % controlPointsNum));

            vertices.push_back(generated[i + 1].getAppliedVertexAt((j + 1) % controlPointsNum));
            vertices.push_back(generated[i + 1].getAppliedVertexAt(j % controlPointsNum));
            vertices.push_back(generated[i].getAppliedVertexAt((j + 1) % controlPointsNum));
        }
        for(int j = 1; j < controlPointsNum - 1; j++)
        {
            vertices.push_back(generated[i].getAppliedVertexAt(0));
            vertices.push_back(generated[i].getAppliedVertexAt(j + 1));
            vertices.push_back(generated[i].getAppliedVertexAt(j));
        }
    }
    for(int j = 1; j < controlPointsNum - 1; j++)
    {
        vertices.push_back(generated[generated.size() - 1].getAppliedVertexAt(0));
        vertices.push_back(generated[generated.size() - 1].getAppliedVertexAt(j + 1));
        vertices.push_back(generated[generated.size() - 1].getAppliedVertexAt(j));
    }
    std::shared_ptr<Object> result = std::make_shared<Object>(vertices);
    return result;
}

std::vector<SplineParser::CrossSection> SplineParser::getSplinedSections(int splineLevel)
{
    std::vector<SplineParser::CrossSection> result;

    for(int i = 0; i < crossSections.size() - 1; i++)
    {
        std::function<Vector3f(float)> positionFunc;
        {
            {
                Vector3f controlPoints[] = {
                    i != 0 ? crossSections[i - 1].position : crossSections[i].position, 
                    crossSections[i].position,
                    crossSections[i + 1].position,
                    i != crossSections.size() - 2 ? crossSections[i + 2].position : crossSections[i + 1].position
                    };

                positionFunc = [controlPoints](float t)
                {
                    Vector3f a[] = {
                        (-t) * controlPoints[0] + (t + 1) * controlPoints[1],
                        (1 - t) * controlPoints[1] + (t) * controlPoints[2],
                        (2 - t) * controlPoints[2] + (t - 1) * controlPoints[3]
                    };
                    Vector3f b[] = {
                        (1 - t) * 0.5 * a[0] + (t + 1) * 0.5 * a[1],
                        (2 - t) * 0.5 * a[1] + (t) * 0.5 * a[2]
                    };
                    return (1 - t) * b[0] + t * b[1];
                };
            }
        }

        for(int j = 0; j < splineLevel; j++)
        {
            CrossSection cs;
            cs.position = positionFunc((float)j / splineLevel);
            cs.orientation = crossSections[i].orientation;
            cs.scale = crossSections[i].scale;
            cs.surface = crossSections[i].surface;

            result.push_back(cs);
        }
    }

    return result;
}
