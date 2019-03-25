#include "Pod.hpp"

using namespace std;

shared_ptr<Pod> Pod::getPod()
{
    vector<Vec3> dummy;
    shared_ptr<Object> head = std::make_shared<Object>(dummy);
    auto returnPod = make_shared<Pod>(make_shared<Model>(head));
    {
        {
            vector<Vec3> headUpV;
            headUpV.push_back({0.4, 0.6, 0.4});
            headUpV.push_back({0.4, 0.6, -0.4});
            headUpV.push_back({-0.4, 0.6, -0.4});
            headUpV.push_back({-0.4, 0.6, 0.4});

            shared_ptr<Object> headUp = std::make_shared<Object>(headUpV);
            headUp->setColor({0.8, 0.8, 0.8});
            head->addChild(move(headUp));
        }

        {
            vector<Vec3> headUpLeftV;
            headUpLeftV.push_back({-0.4, 0.6, 0.4});
            headUpLeftV.push_back({-0.4, 0.6, -0.4});
            headUpLeftV.push_back({-0.5, 0.5, -0.4});
            headUpLeftV.push_back({-0.5, 0.5, 0.4});

            shared_ptr<Object> headUpLeft = std::make_shared<Object>(headUpLeftV);
            headUpLeft->setColor({0.8, 0.8, 0.8});
            head->addChild(move(headUpLeft));
        }

        {
            vector<Vec3> headDownV;
            headDownV.push_back({0.4, -0.6, 0.4});
            headDownV.push_back({0.4, -0.6, -0.4});
            headDownV.push_back({-0.4, -0.6, -0.4});
            headDownV.push_back({-0.4, -0.6, 0.4});

            shared_ptr<Object> headDown = std::make_shared<Object>(headDownV);
            headDown->setColor({0.8, 0.8, 0.8});
            head->addChild(move(headDown));
        }

        {
            vector<Vec3> headUpRightV;
            headUpRightV.push_back({0.4, 0.6, 0.4});
            headUpRightV.push_back({0.4, 0.6, -0.4});
            headUpRightV.push_back({0.5, 0.5, -0.4});
            headUpRightV.push_back({0.5, 0.5, 0.4});

            shared_ptr<Object> headUpRight = std::make_shared<Object>(headUpRightV);
            headUpRight->setColor({0.8, 0.8, 0.8});
            head->addChild(move(headUpRight));
        }

        {
            vector<Vec3> headLeftV;
            headLeftV.push_back({-0.5, 0.5, 0.4});
            headLeftV.push_back({-0.5, 0.5, -0.4});
            headLeftV.push_back({-0.5, -0.5, -0.4});
            headLeftV.push_back({-0.5, -0.5, 0.4});

            shared_ptr<Object> headLeft = std::make_shared<Object>(headLeftV);
            headLeft->setColor({0.8, 0.8, 0.8});
            head->addChild(move(headLeft));
        }

        {
            vector<Vec3> headDownRightV;
            headDownRightV.push_back({0.4, -0.6, 0.4});
            headDownRightV.push_back({0.4, -0.6, -0.4});
            headDownRightV.push_back({0.5, -0.5, -0.4});
            headDownRightV.push_back({0.5, -0.5, 0.4});

            shared_ptr<Object> headDownRight = std::make_shared<Object>(headDownRightV);
            headDownRight->setColor({0.8, 0.8, 0.8});
            head->addChild(move(headDownRight));
        }

        {
            vector<Vec3> headRightV;
            headRightV.push_back({0.5, 0.5, 0.4});
            headRightV.push_back({0.5, 0.5, -0.4});
            headRightV.push_back({0.5, -0.5, -0.4});
            headRightV.push_back({0.5, -0.5, 0.4});

            shared_ptr<Object> headRight = std::make_shared<Object>(headRightV);
            headRight->setColor({0.8, 0.8, 0.8});
            head->addChild(move(headRight));
        }

        {
            vector<Vec3> headDownLeftV;
            headDownLeftV.push_back({-0.4, -0.6, 0.4});
            headDownLeftV.push_back({-0.4, -0.6, -0.4});
            headDownLeftV.push_back({-0.5, -0.5, -0.4});
            headDownLeftV.push_back({-0.5, -0.5, 0.4});

            shared_ptr<Object> headDownLeft = std::make_shared<Object>(headDownLeftV);
            headDownLeft->setColor({0.8, 0.8, 0.8});
            head->addChild(move(headDownLeft));
        }

        {
            vector<Vec3> headFrontV;
            headFrontV.push_back({0.4, 0.6, 0.4});
            headFrontV.push_back({-0.4, 0.6, 0.4});
            headFrontV.push_back({-0.5, 0.5, 0.4});
            headFrontV.push_back({-0.5, -0.5, 0.4});
            headFrontV.push_back({-0.4, -0.6, 0.4});
            headFrontV.push_back({0.4, -0.6, 0.4});
            headFrontV.push_back({0.5, -0.5, 0.4});
            headFrontV.push_back({0.5, 0.5, 0.4});
            headFrontV.push_back({0.4, 0.6, 0.4});

            shared_ptr<Object> headFront = std::make_shared<Object>(headFrontV);
            headFront->setColor({0.8, 0.8, 0.8});
            head->addChild(move(headFront));
        }

        {
            vector<Vec3> headBackV;
            headBackV.push_back({0.4, 0.6, -0.4});
            headBackV.push_back({-0.4, 0.6, -0.4});
            headBackV.push_back({-0.5, 0.5, -0.4});
            headBackV.push_back({-0.5, -0.5, -0.4});
            headBackV.push_back({-0.4, -0.6, -0.4});
            headBackV.push_back({0.4, -0.6, -0.4});
            headBackV.push_back({0.5, -0.5, -0.4});
            headBackV.push_back({0.5, 0.5, -0.4});
            headBackV.push_back({0.4, 0.6, -0.4});

            shared_ptr<Object> headBack = std::make_shared<Object>(headBackV);
            headBack->setColor({0.8, 0.8, 0.8});
            head->addChild(move(headBack));
        }
    }

    {
        shared_ptr<Object> leftLeg = make_shared<Object>(dummy);
        {
            vector<Vec3> leftLegUpV;
            for(int i = 0; i < 10; i++)
            {
                leftLegUpV.push_back({(float)(0.1 * cos(i * 2 * M_PI / 10)), 0, (float)(0.1 * sin(i * 2 * M_PI / 10))});
            }
            shared_ptr<Object> leftLegUp = make_shared<Object>(leftLegUpV);
            leftLeg->addChild(move(leftLegUp));
        }

        {
            vector<Vec3> leftLegDownV;
            for(int i = 0; i < 10; i++)
            {
                leftLegDownV.push_back({(float)(0.1 * cos(i * 2 * M_PI / 10)), -1, (float)(0.1 * sin(i * 2 * M_PI / 10))});
            }
            shared_ptr<Object> leftLegDown = make_shared<Object>(leftLegDownV);
            leftLeg->addChild(move(leftLegDown));
        }

        {
            for(int i = 0; i < 10; i++)
            {
                vector<Vec3> leftLegSideV;
                leftLegSideV.push_back({(float)(0.1 * cos(i * 2 * M_PI / 10)), 0, (float)(0.1 * sin(i * 2 * M_PI / 10))});
                leftLegSideV.push_back({(float)(0.1 * cos(i * 2 * M_PI / 10)), -1, (float)(0.1 * sin(i * 2 * M_PI / 10))});
                leftLegSideV.push_back({(float)(0.1 * cos((i + 1) * 2 * M_PI / 10)), -1, (float)(0.1 * sin((i + 1) * 2 * M_PI / 10))});
                leftLegSideV.push_back({(float)(0.1 * cos((i + 1) * 2 * M_PI / 10)), 0, (float)(0.1 * sin((i + 1) * 2 * M_PI / 10))});

                
                leftLeg->addChild(move(make_shared<Object>(leftLegSideV)));
            }
        }
        leftLeg->setPosition({0.2, -0.7, 0});
        leftLeg->setRotation(60, {-1, 0, 0});
        returnPod->leftThigh = leftLeg;
        
        {
            shared_ptr<Object> secondLeftLeg = make_shared<Object>(dummy);
            {
                vector<Vec3> leftLegUpV;
                for(int i = 0; i < 10; i++)
                {
                    leftLegUpV.push_back({(float)(0.1 * cos(i * 2 * M_PI / 10)), 0, (float)(0.1 * sin(i * 2 * M_PI / 10))});
                }
                shared_ptr<Object> leftLegUp = make_shared<Object>(leftLegUpV);
                secondLeftLeg->addChild(move(leftLegUp));
            }

            {
                vector<Vec3> leftLegDownV;
                for(int i = 0; i < 10; i++)
                {
                    leftLegDownV.push_back({(float)(0.1 * cos(i * 2 * M_PI / 10)), -1, (float)(0.1 * sin(i * 2 * M_PI / 10))});
                }
                shared_ptr<Object> leftLegDown = make_shared<Object>(leftLegDownV);
                secondLeftLeg->addChild(move(leftLegDown));
            }

            {
                for(int i = 0; i < 10; i++)
                {
                    vector<Vec3> leftLegSideV;
                    leftLegSideV.push_back({(float)(0.1 * cos(i * 2 * M_PI / 10)), 0, (float)(0.1 * sin(i * 2 * M_PI / 10))});
                    leftLegSideV.push_back({(float)(0.1 * cos(i * 2 * M_PI / 10)), -1, (float)(0.1 * sin(i * 2 * M_PI / 10))});
                    leftLegSideV.push_back({(float)(0.1 * cos((i + 1) * 2 * M_PI / 10)), -1, (float)(0.1 * sin((i + 1) * 2 * M_PI / 10))});
                    leftLegSideV.push_back({(float)(0.1 * cos((i + 1) * 2 * M_PI / 10)), 0, (float)(0.1 * sin((i + 1) * 2 * M_PI / 10))});
                    
                    secondLeftLeg->addChild(move(make_shared<Object>(leftLegSideV)));
                }
            }
            secondLeftLeg->setPosition({0, -1.1, 0});
            secondLeftLeg->setRotation(-150, {-1, 0, 0});
            returnPod->leftLeg = secondLeftLeg;

            leftLeg->addChild(move(secondLeftLeg));
        }

        head->addChild(move(leftLeg));
    }


    {
        shared_ptr<Object> rightLeg = make_shared<Object>(dummy);
        {
            vector<Vec3> rightLegUpV;
            for(int i = 0; i < 10; i++)
            {
                rightLegUpV.push_back({(float)(0.1 * cos(i * 2 * M_PI / 10)), 0, (float)(0.1 * sin(i * 2 * M_PI / 10))});
            }
            shared_ptr<Object> leftLegUp = make_shared<Object>(rightLegUpV);
            rightLeg->addChild(move(leftLegUp));
        }

        {
            vector<Vec3> rightLegDownV;
            for(int i = 0; i < 10; i++)
            {
                rightLegDownV.push_back({(float)(0.1 * cos(i * 2 * M_PI / 10)), -1, (float)(0.1 * sin(i * 2 * M_PI / 10))});
            }
            shared_ptr<Object> rightLegDown = make_shared<Object>(rightLegDownV);
            rightLeg->addChild(move(rightLegDown));
        }

        {
            for(int i = 0; i < 10; i++)
            {
                vector<Vec3> rightLegSideV;
                rightLegSideV.push_back({(float)(0.1 * cos(i * 2 * M_PI / 10)), 0, (float)(0.1 * sin(i * 2 * M_PI / 10))});
                rightLegSideV.push_back({(float)(0.1 * cos(i * 2 * M_PI / 10)), -1, (float)(0.1 * sin(i * 2 * M_PI / 10))});
                rightLegSideV.push_back({(float)(0.1 * cos((i + 1) * 2 * M_PI / 10)), -1, (float)(0.1 * sin((i + 1) * 2 * M_PI / 10))});
                rightLegSideV.push_back({(float)(0.1 * cos((i + 1) * 2 * M_PI / 10)), 0, (float)(0.1 * sin((i + 1) * 2 * M_PI / 10))});

                
                rightLeg->addChild(move(make_shared<Object>(rightLegSideV)));
            }
        }
        rightLeg->setPosition({-0.2, -0.7, 0});
        rightLeg->setRotation(60, {-1, 0, 0});
        returnPod->rightThigh = rightLeg;

        {
            shared_ptr<Object> secondRightLeg = make_shared<Object>(dummy);
            {
                vector<Vec3> rightLegUpV;
                for(int i = 0; i < 10; i++)
                {
                    rightLegUpV.push_back({(float)(0.1 * cos(i * 2 * M_PI / 10)), 0, (float)(0.1 * sin(i * 2 * M_PI / 10))});
                }
                shared_ptr<Object> rightLegUp = make_shared<Object>(rightLegUpV);
                secondRightLeg->addChild(move(rightLegUp));
            }

            {
                vector<Vec3> rightLegDownV;
                for(int i = 0; i < 10; i++)
                {
                    rightLegDownV.push_back({(float)(0.1 * cos(i * 2 * M_PI / 10)), -1, (float)(0.1 * sin(i * 2 * M_PI / 10))});
                }
                shared_ptr<Object> rightLegDown = make_shared<Object>(rightLegDownV);
                secondRightLeg->addChild(move(rightLegDown));
            }

            {
                for(int i = 0; i < 10; i++)
                {
                    vector<Vec3> rightLegSideV;
                    rightLegSideV.push_back({(float)(0.1 * cos(i * 2 * M_PI / 10)), 0, (float)(0.1 * sin(i * 2 * M_PI / 10))});
                    rightLegSideV.push_back({(float)(0.1 * cos(i * 2 * M_PI / 10)), -1, (float)(0.1 * sin(i * 2 * M_PI / 10))});
                    rightLegSideV.push_back({(float)(0.1 * cos((i + 1) * 2 * M_PI / 10)), -1, (float)(0.1 * sin((i + 1) * 2 * M_PI / 10))});
                    rightLegSideV.push_back({(float)(0.1 * cos((i + 1) * 2 * M_PI / 10)), 0, (float)(0.1 * sin((i + 1) * 2 * M_PI / 10))});
                    
                    secondRightLeg->addChild(move(make_shared<Object>(rightLegSideV)));
                }
            }
            secondRightLeg->setPosition({0, -1.1, 0});
            secondRightLeg->setRotation(-150, {-1, 0, 0});
            returnPod->rightLeg = secondRightLeg;

            rightLeg->addChild(move(secondRightLeg));
        }
        head->addChild(move(rightLeg));
    }

    return make_shared<Pod>(make_shared<Model>(head));

}

shared_ptr<Model> Pod::getModel()
{
    return podModel;
}

Pod::Pod(shared_ptr<Model> m)
{
    podModel = move(m);
}

void Pod::rotateLeftThigh(float deltaAngle)
{
    leftThigh->setRotationAngle(leftThigh->getRotationAngle() + deltaAngle);
}

void Pod::rotateLeftLeg(float deltaAngle)
{
    leftLeg->setRotationAngle(leftLeg->getRotationAngle() + deltaAngle);
}

void Pod::rotateRightThigh(float deltaAngle)
{
    rightThigh->setRotationAngle(rightThigh->getRotationAngle() + deltaAngle);
}
void Pod::rotateRightLeg(float deltaAngle)
{
    rightLeg->setRotationAngle(rightLeg->getRotationAngle() + deltaAngle);
}