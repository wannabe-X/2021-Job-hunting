/*
 * @Description: 策略模式
 * @Author: Mr. Lee
 * @Date: 2021-08-22 09:28:12
 * @LastEditTime: 2021-08-22 10:19:22
 * @LastEditors: Mr. Lee
 */

#include <vector>
#include <iostream>

using namespace std;

// 抽象武器 武器策略
class WeaponStrategy
{
public:
    virtual void UseWeapon() = 0;
};

class Knife : public WeaponStrategy
{
public:
    virtual void UseWeapon()
    {
        cout << "使用匕首..." << endl;
    }
};

class Ak47 : public WeaponStrategy
{
public:
    virtual void UseWeapon()
    {
        cout << "使用AK47..." << endl;
    }
};

// 角色
class Character
{
public:
    void setWeapon(WeaponStrategy *weapon)
    {
        this->pWeapon = weapon;
    }

    void ThrowWeapon()
    {
        this->pWeapon->UseWeapon();
    }

public:
    WeaponStrategy *pWeapon;
};

void test01()
{
    // 创建角色
    Character *character = new Character();
    // 武器策略
    WeaponStrategy *knife = new Knife();
    WeaponStrategy *ak = new Ak47();

    character->setWeapon(knife);
    character->ThrowWeapon();

    character->setWeapon(ak);
    character->ThrowWeapon();

    delete ak;
    ak = nullptr;
    delete knife;
    knife = nullptr;
    delete character;
    character = nullptr;
}

int main()
{
    test01();
    return 0;
}
