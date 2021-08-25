/*
 * @Description: 面向对象设计法则 - 迪米特法则，最少知识法则
 * @Author: Mr. Lee
 * @Date: 2021-08-18 20:17:48
 * @LastEditTime: 2021-08-18 20:43:29
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 迪米特法则，又叫最少知识法则
class AbstractBuilding
{
public:
    virtual void sale() = 0;
    virtual string getQulity() = 0;
};

class BuildingA : public AbstractBuilding
{
public:
    BuildingA()
    {
        this->mQulity = "high qulity";
    }

    virtual void sale()
    {
        cout << "BuildingA " << mQulity << " saled." << endl;
    }

    virtual string getQulity()
    {
        return mQulity;
    }

public:
    string mQulity;
};

class BuildingB : public AbstractBuilding
{
public:
    BuildingB()
    {
        this->mQulity = "low qulity";
    }

    virtual void sale()
    {
        cout << "BuildingA " << mQulity << " saled." << endl;
    }

    virtual string getQulity()
    {
        return mQulity;
    }

public:
    string mQulity;
};

// 客户端调用
void test01()
{
    BuildingA *bA = new BuildingA();
    if (bA->mQulity == "high qulity")
    {
        bA->sale();
    }

    BuildingB *bB = new BuildingB();
    if (bB->mQulity == "low qulity")
    {
        bB->sale();
    }
}

// 中介类
class Mediator
{
public:
    Mediator()
    {
        AbstractBuilding *building = new BuildingA();
        vBuilding.push_back(building);
        building = new BuildingB();
        vBuilding.push_back(building);
    }

    // 对外提供接口
    AbstractBuilding *findMyBuilding(string qulity)
    {
        for (auto it = vBuilding.begin(); it != vBuilding.end(); it++)
        {
            if ((*it)->getQulity() == qulity)
                return *it;
        }

        return nullptr;
    }

    ~Mediator()
    {
        for (auto it = vBuilding.begin(); it != vBuilding.end(); it++)
        {
            if ((*it) != nullptr)
                delete *it;
        }
    }

public:
    vector<AbstractBuilding *> vBuilding;
};

void test02()
{
    Mediator *mediator = new Mediator();
    AbstractBuilding *building = mediator->findMyBuilding("high qulity");
    if (building)
    {
        building->sale();
    }
    else
    {
        cout << "not found." << endl;
    }
}

int main()
{
    // test01();
    test02();
    return 0;
}