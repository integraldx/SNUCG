#include "Pod.hpp"

using namespace std;

shared_ptr<Pod> Pod::getPod()
{
    vector<Vec3> dummy;
    unique_ptr<Object> head = std::make_unique<Object>(dummy);
    {
        {
            vector<Vec3> headUpV;
            headUpV.push_back({0.4, 0.6, 0.4});
            headUpV.push_back({0.4, 0.6, -0.4});
            headUpV.push_back({-0.4, 0.6, -0.4});
            headUpV.push_back({-0.4, 0.6, 0.4});

            unique_ptr<Object> headUp = std::make_unique<Object>(headUpV);
            headUp->setColor({0.8, 0.8, 0.8});
            head->addChild(move(headUp));
        }

        {
            vector<Vec3> headUpLeftV;
            headUpLeftV.push_back({-0.4, 0.6, 0.4});
            headUpLeftV.push_back({-0.4, 0.6, -0.4});
            headUpLeftV.push_back({-0.5, 0.5, -0.4});
            headUpLeftV.push_back({-0.5, 0.5, 0.4});

            unique_ptr<Object> headUpLeft = std::make_unique<Object>(headUpLeftV);
            headUpLeft->setColor({0.8, 0.8, 0.8});
            head->addChild(move(headUpLeft));
        }

        {
            vector<Vec3> headDownV;
            headDownV.push_back({0.4, -0.6, 0.4});
            headDownV.push_back({0.4, -0.6, -0.4});
            headDownV.push_back({-0.4, -0.6, -0.4});
            headDownV.push_back({-0.4, -0.6, 0.4});

            unique_ptr<Object> headDown = std::make_unique<Object>(headDownV);
            headDown->setColor({0.8, 0.8, 0.8});
            head->addChild(move(headDown));
        }

        {
            vector<Vec3> headUpRightV;
            headUpRightV.push_back({0.4, 0.6, 0.4});
            headUpRightV.push_back({0.4, 0.6, -0.4});
            headUpRightV.push_back({0.5, 0.5, -0.4});
            headUpRightV.push_back({0.5, 0.5, 0.4});

            unique_ptr<Object> headUpRight = std::make_unique<Object>(headUpRightV);
            headUpRight->setColor({0.8, 0.8, 0.8});
            head->addChild(move(headUpRight));
        }

        {
            vector<Vec3> headLeftV;
            headLeftV.push_back({-0.5, 0.5, 0.4});
            headLeftV.push_back({-0.5, 0.5, -0.4});
            headLeftV.push_back({-0.5, -0.5, -0.4});
            headLeftV.push_back({-0.5, -0.5, 0.4});

            unique_ptr<Object> headLeft = std::make_unique<Object>(headLeftV);
            headLeft->setColor({0.8, 0.8, 0.8});
            head->addChild(move(headLeft));
        }

        {
            vector<Vec3> headDownRightV;
            headDownRightV.push_back({0.4, -0.6, 0.4});
            headDownRightV.push_back({0.4, -0.6, -0.4});
            headDownRightV.push_back({0.5, -0.5, -0.4});
            headDownRightV.push_back({0.5, -0.5, 0.4});

            unique_ptr<Object> headDownRight = std::make_unique<Object>(headDownRightV);
            headDownRight->setColor({0.8, 0.8, 0.8});
            head->addChild(move(headDownRight));
        }

        {
            vector<Vec3> headRightV;
            headRightV.push_back({0.5, 0.5, 0.4});
            headRightV.push_back({0.5, 0.5, -0.4});
            headRightV.push_back({0.5, -0.5, -0.4});
            headRightV.push_back({0.5, -0.5, 0.4});

            unique_ptr<Object> headRight = std::make_unique<Object>(headRightV);
            headRight->setColor({0.8, 0.8, 0.8});
            head->addChild(move(headRight));
        }

        {
            vector<Vec3> headDownLeftV;
            headDownLeftV.push_back({-0.4, -0.6, 0.4});
            headDownLeftV.push_back({-0.4, -0.6, -0.4});
            headDownLeftV.push_back({-0.5, -0.5, -0.4});
            headDownLeftV.push_back({-0.5, -0.5, 0.4});

            unique_ptr<Object> headDownLeft = std::make_unique<Object>(headDownLeftV);
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

            unique_ptr<Object> headFront = std::make_unique<Object>(headFrontV);
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

            unique_ptr<Object> headBack = std::make_unique<Object>(headBackV);
            headBack->setColor({0.8, 0.8, 0.8});
            head->addChild(move(headBack));
        }
    }

    {
        unique_ptr<Object> leftLeg = make_unique<Object>(dummy);
        {
            vector<Vec3> leftLegUpV;
            for(int i = 0; i < 10; i++)
            {
                leftLegUpV.push_back({(float)(0.1 * cos(i * 2 * M_PI / 10)), 0, (float)(0.1 * sin(i * 2 * M_PI / 10))});
            }
            unique_ptr<Object> leftLegUp = make_unique<Object>(leftLegUpV);
            leftLeg->addChild(move(leftLegUp));
        }

        {
            vector<Vec3> leftLegDownV;
            for(int i = 0; i < 10; i++)
            {
                leftLegDownV.push_back({(float)(0.1 * cos(i * 2 * M_PI / 10)), -1, (float)(0.1 * sin(i * 2 * M_PI / 10))});
            }
            unique_ptr<Object> leftLegDown = make_unique<Object>(leftLegDownV);
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

                
                leftLeg->addChild(move(make_unique<Object>(leftLegSideV)));
            }
        }
        leftLeg->setPosition({0.2, -0.7, 0});

        head->addChild(move(leftLeg));
    }

    return make_shared<Pod>(make_shared<Model>(move(head)));

}

shared_ptr<Model> Pod::getModel()
{
    return podModel;
}

Pod::Pod(shared_ptr<Model> m)
{
    podModel = move(m);
}