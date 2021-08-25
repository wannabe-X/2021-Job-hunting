/*
 * @Description: 装饰器模式
 * @Author: Mr. Lee
 * @Date: 2021-08-24 21:09:24
 * @LastEditTime: 2021-08-24 22:21:21
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 一般情况下，使用继承实现类的功能拓展
// 装饰模式 可以动态给一个类增加功能

// 抽象的英雄
class AbstractHero
{
public:
    AbstractHero()
    {
        this->mHp = 0;
        this->mMp = 0;
        this->mAt = 0;
        this->mDf = 0;
    }

    virtual void showStatus()
    {
        cout << "血量:" << this->mHp << endl;
        cout << "魔法:" << this->mMp << endl;
        cout << "攻击:" << this->mAt << endl;
        cout << "防御:" << this->mDf << endl;
    }

public:
    int mHp;
    int mMp;
    int mAt;
    int mDf;
};

class HeroA : public AbstractHero
{
public:
    virtual void showStatus() {}
};

// 英雄穿上某个装饰物，还是个英雄。所以要继承AbstractHero
class AbstractEquipment : public AbstractHero
{
public:
    AbstractEquipment(AbstractHero *hero)
    {
        this->pHero = hero;
    }

    virtual void showStatus()
    {
    }

public:
    AbstractHero *pHero;
};

// 狂徒
class KuangtuEquipment : public AbstractEquipment
{
public:
    KuangtuEquipment(AbstractHero *hero) : AbstractEquipment(hero) {}
    // 增加额外的功能
    void AddKuangtu()
    {
        cout << "英雄穿上狂徒装备后..." << endl;
        this->mHp = this->pHero->mHp;
        this->mAt = this->pHero->mAt;
        this->mMp = this->pHero->mMp;
        this->mDf = this->pHero->mDf + 30;

        delete this->pHero;
    }

    virtual void showStatus()
    {
        AddKuangtu();
        cout << "血量:" << this->mHp << endl;
        cout << "魔法:" << this->mMp << endl;
        cout << "攻击:" << this->mAt << endl;
        cout << "防御:" << this->mDf << endl;
    }
};

// 无尽之刃
class Wujinzhiren : public AbstractEquipment
{
public:
    Wujinzhiren(AbstractHero *hero) : AbstractEquipment(hero) {}
    // 增加额外的功能
    void AddWujinzhiren()
    {
        cout << "英雄穿上无尽之刃后..." << endl;
        this->mHp = this->pHero->mHp;
        this->mAt = this->pHero->mAt + 80;
        this->mMp = this->pHero->mMp;
        this->mDf = this->pHero->mDf;

        delete this->pHero;
    }

    virtual void showStatus()
    {
        AddWujinzhiren();
        cout << "血量:" << this->mHp << endl;
        cout << "魔法:" << this->mMp << endl;
        cout << "攻击:" << this->mAt << endl;
        cout << "防御:" << this->mDf << endl;
    }
};

void test01()
{
    AbstractHero *hero = new HeroA();
    hero->showStatus();

    cout << "--------------------------------" << endl;

    // 给英雄穿上衣服
    hero = new KuangtuEquipment(hero);
    hero->showStatus();

    cout << "--------------------------------" << endl;

    // 给影像装备武器
    hero = new Wujinzhiren(hero);
    hero->showStatus();
}

int main(int argc, char *argv[])
{
    test01();
    return 0;
}