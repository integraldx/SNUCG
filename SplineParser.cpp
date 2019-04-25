#include "SplineParser.hpp"

std::shared_ptr<Model> SplineParser::getModelFromTxt(std::string filePath)
{
    enum SplineKind{BSPLINE, CATMULL_ROM} splineKind;
    enum parsingState {KIND, CROSSNUM, CTRLPNTNUM, CTRLPNT, SCAL, ROT, POS, CLEAR} state = KIND;
    std::ifstream stream(filePath.data());

    std::vector<Vector3f> v;
    std::shared_ptr<Object> rootObj = std::make_shared<Object>(v);
    int crossSectionNum;
    int controlPointNumPerCross;
    std::vector<Vector3f> controlPointsV;
    int tempCounter = 0;
    float tempScalingFactor;
    Quaternion tempRotation;
    Vector3f tempPosition;

    if (stream.is_open())
    {
        std::string s;
        while (std::getline(stream, s))
        {
            int commentIndex = s.find_first_of('#');
            s = s.substr(0, commentIndex);
            if(s.size() == 0 || s[0] == ' ')
            {
                continue;
            }
            std::stringstream ss(s);

            if (state == KIND)
            {
                std::string kindString;
                ss >> kindString;
                splineKind = kindString.compare("BSPLINE") ? BSPLINE : CATMULL_ROM;
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
                state = CTRLPNT;
            }
            else if (state == CTRLPNT)
            {
                float x, z;
                ss >> x >> z;
                controlPointsV.push_back({x, 0, z});
                tempCounter++;
                printf("%f %f\n", x, z);
                if(tempCounter >= controlPointNumPerCross)
                {
                    tempCounter == 0;
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
                state = CLEAR;
            }

            if (state == CLEAR)
            {
                std::shared_ptr<SplinedObject> newObj = std::make_shared<SplinedObject>(controlPointsV, 10);
                newObj->setPosition(tempPosition);
                newObj->setRotation(tempRotation);
                newObj->setScale({tempScalingFactor, tempScalingFactor, tempScalingFactor});
                newObj->setColor({1, 1, 1});
                rootObj->addChild(std::move(std::dynamic_pointer_cast<Object>(newObj)));

                state = CTRLPNT;
            }
        }
        stream.close();
    }
    else
    {
        std::cout << "File not found." << std::endl;
        exit(1);
    }

    return std::make_shared<Model>(move(rootObj));
}