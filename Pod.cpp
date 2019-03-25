#include "Pod.hpp"

using namespace std;
shared_ptr<Model> Pod::getPod()
{
    vector<Vec3> dummy;
    std::unique_ptr<Object> head = std::make_unique<Object>(dummy);
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

    return make_shared<Model>(move(head));
}