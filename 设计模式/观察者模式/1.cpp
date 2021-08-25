/*
 * @Description: 观察者模式
 * @Author: Mr. Lee
 * @Date: 2021-08-24 20:38:17
 * @LastEditTime: 2021-08-24 21:07:18
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

// 抽象的英雄
class AbstractHero
{
public:
    virtual void Update() = 0;
};

// 具体英雄 具体观察者
class HeroA : public AbstractHero
{
public:
    HeroA()
    {
        cout << "英雄A正在攻击BOSS..." << endl;
    }

    virtual void Update()
    {
        cout << "英雄A停止攻击BOSS，处于待机状态..." << endl;
    }
};

class HeroB : public AbstractHero
{
public:
    HeroB()
    {
        cout << "英雄B正在攻击BOSS..." << endl;
    }

    virtual void Update()
    {
        cout << "英雄B停止攻击BOSS，处于待机状态..." << endl;
    }
};

class HeroC : public AbstractHero
{
public:
    HeroC()
    {
        cout << "英雄C正在攻击BOSS..." << endl;
    }

    virtual void Update()
    {
        cout << "英雄C停止攻击BOSS，处于待机状态..." << endl;
    }
};

class HeroD : public AbstractHero
{
public:
    HeroD()
    {
        cout << "英雄D正在攻击BOSS..." << endl;
    }

    virtual void Update()
    {
        cout << "英雄D停止攻击BOSS，处于待机状态..." << endl;
    }
};

class HeroE : public AbstractHero
{
public:
    HeroE()
    {
        cout << "英雄E正在攻击BOSS..." << endl;
    }

    virtual void Update()
    {
        cout << "英雄E停止攻击BOSS，处于待机状态..." << endl;
    }
};

// 抽象观察目标
class AbstractBoss
{
public:
    virtual void addHero(AbstractHero *hero) = 0;    // 增加观察者
    virtual void deleteHero(AbstractHero *boss) = 0; // 删除观察者
    virtual void notify() = 0;                       // 通知观察者
};

// 具体的观察者
class BossA : public AbstractBoss
{
public:
    virtual void addHero(AbstractHero *hero)
    {
        pHeroList.push_back(hero);
    }

    virtual void deleteHero(AbstractHero *hero)
    {
        pHeroList.remove(hero);
    }

    virtual void notify()
    {
        for (list<AbstractHero *>::iterator it = pHeroList.begin(); it != pHeroList.end(); it++)
        {
            (*it)->Update();
        }
    }

public:
    list<AbstractHero *> pHeroList;
};

//
void test01()
{
    // 创建观察者
    AbstractHero *heroA = new HeroA();
    AbstractHero *heroB = new HeroB();
    AbstractHero *heroC = new HeroC();
    AbstractHero *heroD = new HeroD();
    AbstractHero *heroE = new HeroE();

    cout << endl;

    // 创建观察目标
    AbstractBoss *boss = new BossA();
    boss->addHero(heroA);
    boss->addHero(heroB);
    boss->addHero(heroC);
    boss->addHero(heroD);
    boss->addHero(heroE);

    // heroC已阵亡
    cout << "heroC阵亡..." << endl;

    cout << endl;

    boss->deleteHero(heroC);

    cout << "Boss已被消灭...通知其他英雄停止攻击，抢装备..." << endl;

    cout << endl;

    boss->notify();
}

int main(int argc, char *argv[])
{
    test01();

    return 0;
}