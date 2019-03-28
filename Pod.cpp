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

        {
            vector<Vec3> headBottomDownV;
            headBottomDownV.push_back({0.3, -1.0, 0.3});
            headBottomDownV.push_back({0.3, -1.0, -0.3});
            headBottomDownV.push_back({-0.3, -1.0, -0.3});
            headBottomDownV.push_back({-0.3, -1.0, 0.3});

            shared_ptr<Object> headBottomDown = std::make_shared<Object>(headBottomDownV);
            headBottomDown->setColor({0.4, 0.4, 0.4});
            head->addChild(move(headBottomDown));
        }

        {
            vector<Vec3> headBottomLeftV;
            headBottomLeftV.push_back({0.3, -0.6, 0.3});
            headBottomLeftV.push_back({0.3, -0.6, -0.3});
            headBottomLeftV.push_back({0.3, -1.0, -0.3});
            headBottomLeftV.push_back({0.3, -1.0, 0.3});

            shared_ptr<Object> headBottomLeft = std::make_shared<Object>(headBottomLeftV);
            headBottomLeft->setColor({0.4, 0.4, 0.4});
            head->addChild(move(headBottomLeft));
        }

        {
            vector<Vec3> headBottomRightV;
            headBottomRightV.push_back({-0.3, -0.6, 0.3});
            headBottomRightV.push_back({-0.3, -0.6, -0.3});
            headBottomRightV.push_back({-0.3, -1.0, -0.3});
            headBottomRightV.push_back({-0.3, -1.0, 0.3});

            shared_ptr<Object> headBottomRight = std::make_shared<Object>(headBottomRightV);
            headBottomRight->setColor({0.4, 0.4, 0.4});
            head->addChild(move(headBottomRight));
        }

        {
            vector<Vec3> headBottomFrontV;
            headBottomFrontV.push_back({-0.3, -0.6, -0.3});
            headBottomFrontV.push_back({0.3, -0.6, -0.3});
            headBottomFrontV.push_back({0.3, -1.0, -0.3});
            headBottomFrontV.push_back({-0.3, -1.0, -0.3});

            shared_ptr<Object> headBottomFront = std::make_shared<Object>(headBottomFrontV);
            headBottomFront->setColor({0.4, 0.4, 0.4});
            head->addChild(move(headBottomFront));
        }

        {
            vector<Vec3> headBottomBackV;
            headBottomBackV.push_back({-0.3, -0.6, 0.3});
            headBottomBackV.push_back({0.3, -0.6, 0.3});
            headBottomBackV.push_back({0.3, -1.0, 0.3});
            headBottomBackV.push_back({-0.3, -1.0, 0.3});

            shared_ptr<Object> headBottomBack = std::make_shared<Object>(headBottomBackV);
            headBottomBack->setColor({0.4, 0.4, 0.4});
            head->addChild(move(headBottomBack));
        }

        {
            for(int i = 0; i < 10; i++)
            {
                vector<Vec3> headTopColumnV;
                headTopColumnV.push_back({0.03 * sin(M_PI * (double)i / 5.0) + 0.3, 0.6, -0.3 + 0.03 * cos(M_PI * (double) i / 5.0)});
                headTopColumnV.push_back({0.03 * sin(M_PI * (double)i / 5.0) + 0.3, 0.75, -0.3 + 0.03 * cos(M_PI * (double) i / 5.0)});
                headTopColumnV.push_back({0.03 * sin(M_PI * (double)(i + 1) / 5.0) + 0.3, 0.75, -0.3 + 0.03 * cos(M_PI * (double)(i + 1) / 5.0)});
                headTopColumnV.push_back({0.03 * sin(M_PI * (double)(i + 1) / 5.0) + 0.3, 0.6, -0.3 + 0.03 * cos(M_PI * (double)(i + 1) / 5.0)});

                shared_ptr<Object> headTopColumn = std::make_shared<Object>(headTopColumnV);
                headTopColumn->setColor({0.5, 0.5, 0.5});
                head->addChild(move(headTopColumn));
            }
        }

        {
            vector<Vec3> headTopCylinderV;
            for(int i = 0; i < 10; i++)
            {
                headTopCylinderV.push_back({0.3 + 0.15 * sin(M_PI * (double)i / 5.0), 0.75, -0.3 + 0.15 * cos(M_PI * (double)i / 5.0)});
            }
            shared_ptr<Object> headTopCylinder = std::make_shared<Object>(headTopCylinderV);
            headTopCylinder->setColor({0.6, 0.3, 0.3});
            head->addChild(move(headTopCylinder));
        }

        {
            vector<Vec3> headTopCylinderV;
            for(int i = 0; i < 10; i++)
            {
                headTopCylinderV.push_back({0.3 + 0.15 * sin(M_PI * (double)i / 5.0), 1.05, -0.3 + 0.15 * cos(M_PI * (double)i / 5.0)});
            }
            shared_ptr<Object> headTopCylinder = std::make_shared<Object>(headTopCylinderV);
            headTopCylinder->setColor({0.6, 0.3, 0.3});
            head->addChild(move(headTopCylinder));
        }

        {
            for(int i = 0; i < 10; i++)
            {
                vector<Vec3> headTopColumnV;
                headTopColumnV.push_back({0.15 * sin(M_PI * (double)i / 5.0) + 0.3, 1.05, -0.3 + 0.15 * cos(M_PI * (double) i / 5.0)});
                headTopColumnV.push_back({0.15 * sin(M_PI * (double)i / 5.0) + 0.3, 0.75, -0.3 + 0.15 * cos(M_PI * (double) i / 5.0)});
                headTopColumnV.push_back({0.15 * sin(M_PI * (double)(i + 1) / 5.0) + 0.3, 0.75, -0.3 + 0.15 * cos(M_PI * (double)(i + 1) / 5.0)});
                headTopColumnV.push_back({0.15 * sin(M_PI * (double)(i + 1) / 5.0) + 0.3, 1.05, -0.3 + 0.15 * cos(M_PI * (double)(i + 1) / 5.0)});

                shared_ptr<Object> headTopColumn = std::make_shared<Object>(headTopColumnV);
                headTopColumn->setColor({0.6, 0.3, 0.3});
                head->addChild(move(headTopColumn));
            }
        }
    }

    {
        shared_ptr<Object> leftLeg = make_shared<Object>(dummy);
        {
            vector<Vec3> leftLegUpV;
            for(int i = 0; i < 10; i++)
            {
                leftLegUpV.push_back({(float)(0.05 * cos(i * 2 * M_PI / 10)), 0, (float)(0.05 * sin(i * 2 * M_PI / 10))});
            }
            shared_ptr<Object> leftLegUp = make_shared<Object>(leftLegUpV);
            leftLeg->addChild(move(leftLegUp));
        }

        {
            vector<Vec3> leftLegDownV;
            for(int i = 0; i < 10; i++)
            {
                leftLegDownV.push_back({(float)(0.05 * cos(i * 2 * M_PI / 10)), -0.6, (float)(0.05 * sin(i * 2 * M_PI / 10))});
            }
            shared_ptr<Object> leftLegDown = make_shared<Object>(leftLegDownV);
            leftLeg->addChild(move(leftLegDown));
        }

        {
            for(int i = 0; i < 10; i++)
            {
                vector<Vec3> leftLegSideV;
                leftLegSideV.push_back({(float)(0.05 * cos(i * 2 * M_PI / 10)), 0, (float)(0.05 * sin(i * 2 * M_PI / 10))});
                leftLegSideV.push_back({(float)(0.05 * cos(i * 2 * M_PI / 10)), -0.6, (float)(0.05 * sin(i * 2 * M_PI / 10))});
                leftLegSideV.push_back({(float)(0.05 * cos((i + 1) * 2 * M_PI / 10)), -0.6, (float)(0.05 * sin((i + 1) * 2 * M_PI / 10))});
                leftLegSideV.push_back({(float)(0.05 * cos((i + 1) * 2 * M_PI / 10)), 0, (float)(0.05 * sin((i + 1) * 2 * M_PI / 10))});

                
                leftLeg->addChild(move(make_shared<Object>(leftLegSideV)));
            }
        }

        {
            vector<Vec3> leftLegJointV;
            for(int i = 0; i < 10; i++)
            {
                leftLegJointV.push_back({0.1, (float)(0.1 * sin(i * 2 * M_PI / 10)), (float)(0.1 * cos(i * 2 * M_PI / 10))});
            }

            leftLeg->addChild(make_shared<Object>(leftLegJointV));
        }

        {
            for(int i = 0; i < 10; i++)
            {
                vector<Vec3> leftLegJointV;
                leftLegJointV.push_back({0.1, (float)(0.1 * cos(i * 2 * M_PI / 10)), (float)(0.1 * sin(i * 2 * M_PI / 10))});
                leftLegJointV.push_back({-0.1, (float)(0.1 * cos(i * 2 * M_PI / 10)), (float)(0.1 * sin(i * 2 * M_PI / 10))});
                leftLegJointV.push_back({-0.1, (float)(0.1 * cos((i + 1) * 2 * M_PI / 10)), (float)(0.1 * sin((i + 1) * 2 * M_PI / 10))});
                leftLegJointV.push_back({0.1, (float)(0.1 * cos((i + 1) * 2 * M_PI / 10)), (float)(0.1 * sin((i + 1) * 2 * M_PI / 10))});

                
                leftLeg->addChild(move(make_shared<Object>(leftLegJointV)));
            }
        }

        {
            vector<Vec3> leftLegJointV;
            for(int i = 0; i < 10; i++)
            {
                leftLegJointV.push_back({0.1, (float)(0.1 * sin(i * 2 * M_PI / 10)) - 0.6, (float)(0.1 * cos(i * 2 * M_PI / 10))});
            }

            leftLeg->addChild(make_shared<Object>(leftLegJointV));
        }

        {
            vector<Vec3> leftLegJointV;
            for(int i = 0; i < 10; i++)
            {
                leftLegJointV.push_back({-0.1, (float)(0.1 * sin(i * 2 * M_PI / 10)) - 0.6, (float)(0.1 * cos(i * 2 * M_PI / 10))});
            }

            leftLeg->addChild(make_shared<Object>(leftLegJointV));
        }

        {
            for(int i = 0; i < 10; i++)
            {
                vector<Vec3> leftLegJointV;
                leftLegJointV.push_back({0.1, (float)(0.1 * cos(i * 2 * M_PI / 10)) - 0.6, (float)(0.1 * sin(i * 2 * M_PI / 10))});
                leftLegJointV.push_back({-0.1, (float)(0.1 * cos(i * 2 * M_PI / 10)) - 0.6, (float)(0.1 * sin(i * 2 * M_PI / 10))});
                leftLegJointV.push_back({-0.1, (float)(0.1 * cos((i + 1) * 2 * M_PI / 10)) - 0.6, (float)(0.1 * sin((i + 1) * 2 * M_PI / 10))});
                leftLegJointV.push_back({0.1, (float)(0.1 * cos((i + 1) * 2 * M_PI / 10)) - 0.6, (float)(0.1 * sin((i + 1) * 2 * M_PI / 10))});

                
                leftLeg->addChild(move(make_shared<Object>(leftLegJointV)));
            }
        }

        leftLeg->setPosition({0.4, -0.8, 0});
        leftLeg->setRotation(30, {-1, 0, 0});
        leftLeg->setColor({0.2, 0.2, 0.2});

        returnPod->legs.push_back(leftLeg);
        
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
            secondLeftLeg->setPosition({0, -0.7, 0});
            secondLeftLeg->setRotation(-120, {-1, 0, 0});
            secondLeftLeg->setColor({0.8, 0.8, 0.8});
            returnPod->legs.push_back(shared_ptr<Object>(secondLeftLeg));

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
                rightLegUpV.push_back({(float)(0.05 * cos(i * 2 * M_PI / 10)), 0, (float)(0.05 * sin(i * 2 * M_PI / 10))});
            }
            shared_ptr<Object> leftLegUp = make_shared<Object>(rightLegUpV);
            rightLeg->addChild(move(leftLegUp));
        }

        {
            vector<Vec3> rightLegDownV;
            for(int i = 0; i < 10; i++)
            {
                rightLegDownV.push_back({(float)(0.05 * cos(i * 2 * M_PI / 10)), -0.6, (float)(0.05 * sin(i * 2 * M_PI / 10))});
            }
            shared_ptr<Object> rightLegDown = make_shared<Object>(rightLegDownV);
            rightLeg->addChild(move(rightLegDown));
        }

        {
            for(int i = 0; i < 10; i++)
            {
                vector<Vec3> rightLegSideV;
                rightLegSideV.push_back({(float)(0.05 * cos(i * 2 * M_PI / 10)), 0, (float)(0.05 * sin(i * 2 * M_PI / 10))});
                rightLegSideV.push_back({(float)(0.05 * cos(i * 2 * M_PI / 10)), -0.6, (float)(0.05 * sin(i * 2 * M_PI / 10))});
                rightLegSideV.push_back({(float)(0.05 * cos((i + 1) * 2 * M_PI / 10)), -0.6, (float)(0.05 * sin((i + 1) * 2 * M_PI / 10))});
                rightLegSideV.push_back({(float)(0.05 * cos((i + 1) * 2 * M_PI / 10)), 0, (float)(0.05 * sin((i + 1) * 2 * M_PI / 10))});

                
                rightLeg->addChild(move(make_shared<Object>(rightLegSideV)));
            }
        }

        {
            vector<Vec3> rightLegJointV;
            for(int i = 0; i < 10; i++)
            {
                rightLegJointV.push_back({-0.1, (float)(0.1 * sin(i * 2 * M_PI / 10)), (float)(0.1 * cos(i * 2 * M_PI / 10))});
            }

            rightLeg->addChild(make_shared<Object>(rightLegJointV));
        }

        {
            for(int i = 0; i < 10; i++)
            {
                vector<Vec3> rightLegJointV;
                rightLegJointV.push_back({0.1, (float)(0.1 * cos(i * 2 * M_PI / 10)), (float)(0.1 * sin(i * 2 * M_PI / 10))});
                rightLegJointV.push_back({-0.1, (float)(0.1 * cos(i * 2 * M_PI / 10)), (float)(0.1 * sin(i * 2 * M_PI / 10))});
                rightLegJointV.push_back({-0.1, (float)(0.1 * cos((i + 1) * 2 * M_PI / 10)), (float)(0.1 * sin((i + 1) * 2 * M_PI / 10))});
                rightLegJointV.push_back({0.1, (float)(0.1 * cos((i + 1) * 2 * M_PI / 10)), (float)(0.1 * sin((i + 1) * 2 * M_PI / 10))});

                
                rightLeg->addChild(move(make_shared<Object>(rightLegJointV)));
            }
        }

        {
            vector<Vec3> rightLegJointV;
            for(int i = 0; i < 10; i++)
            {
                rightLegJointV.push_back({-0.1, (float)(0.1 * sin(i * 2 * M_PI / 10)) - 0.6, (float)(0.1 * cos(i * 2 * M_PI / 10))});
            }

            rightLeg->addChild(make_shared<Object>(rightLegJointV));
        }

        {
            for(int i = 0; i < 10; i++)
            {
                vector<Vec3> rightLegJointV;
                rightLegJointV.push_back({0.1, (float)(0.1 * cos(i * 2 * M_PI / 10)) - 0.6, (float)(0.1 * sin(i * 2 * M_PI / 10))});
                rightLegJointV.push_back({-0.1, (float)(0.1 * cos(i * 2 * M_PI / 10)) - 0.6, (float)(0.1 * sin(i * 2 * M_PI / 10))});
                rightLegJointV.push_back({-0.1, (float)(0.1 * cos((i + 1) * 2 * M_PI / 10)) - 0.6, (float)(0.1 * sin((i + 1) * 2 * M_PI / 10))});
                rightLegJointV.push_back({0.1, (float)(0.1 * cos((i + 1) * 2 * M_PI / 10)) - 0.6, (float)(0.1 * sin((i + 1) * 2 * M_PI / 10))});

                
                rightLeg->addChild(move(make_shared<Object>(rightLegJointV)));
            }
        }

        {
            vector<Vec3> rightLegJointV;
            for(int i = 0; i < 10; i++)
            {
                rightLegJointV.push_back({0.1, (float)(0.1 * sin(i * 2 * M_PI / 10)) - 0.6, (float)(0.1 * cos(i * 2 * M_PI / 10))});
            }

            rightLeg->addChild(make_shared<Object>(rightLegJointV));
        }
        rightLeg->setPosition({-0.4, -0.8, 0});
        rightLeg->setRotation(30, {-1, 0, 0});
        rightLeg->setColor({0.2, 0.2, 0.2});
        returnPod->legs.push_back(rightLeg);

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
            secondRightLeg->setPosition({0, -0.7, 0});
            secondRightLeg->setRotation(-120, {-1, 0, 0});
            secondRightLeg->setColor({0.8, 0.8, 0.8});

            returnPod->legs.push_back(secondRightLeg);
            rightLeg->addChild(move(secondRightLeg));
        }
        head->addChild(move(rightLeg));
    }

    return returnPod;

}

shared_ptr<Model> Pod::getModel()
{
    return podModel;
}

Pod::Pod(shared_ptr<Model> m)
{
    podModel = move(m);
}

void Pod::rotateLeftThigh(float angle)
{
    legs[0]->setRotationAngle(angle);
}

void Pod::rotateLeftLeg(float angle)
{
    legs[1]->setRotationAngle(angle);
}

void Pod::rotateRightThigh(float angle)
{
    legs[2]->setRotationAngle(angle);
}

void Pod::rotateRightLeg(float angle)
{
    legs[3]->setRotationAngle(angle);
}

void Pod::setPosition(Vec3 v)
{
    podModel->setPosition(v);
}

void Pod::setRotation(float f, Vec3 v)
{
    podModel->setRotation(f, v);
}

void Pod::setScale(Vec3 v)
{
    podModel->setScale(v);
}

