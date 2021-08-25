/*
 * @Description: 模板方法模式
 * @Author: Mr. Lee
 * @Date: 2021-08-22 08:26:33
 * @LastEditTime: 2021-08-22 08:38:41
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>

using namespace std;

class DrinkTemplate
{
public:
    virtual void boildWater() = 0;   // 煮水
    virtual void Brew() = 0;         // 冲泡
    virtual void PourInCup() = 0;    // 倒入杯中
    virtual void AddSomething() = 0; // 添加辅料
public:
    void Make()
    {
        // 步骤固定，实现细节不同
        this->boildWater();
        this->Brew();
        this->PourInCup();
        this->AddSomething();
    }
};

class Coffee : public DrinkTemplate
{
public:
    virtual void boildWater()
    {
        cout << "煮山泉水..." << endl;
    }
    virtual void Brew()
    {
        cout << "冲泡咖啡..." << endl;
    }
    virtual void PourInCup()
    {
        cout << "将咖啡倒入杯中..." << endl;
    }
    virtual void AddSomething()
    {
        cout << "加牛奶，加五分糖..." << endl;
    }
};

class Tea : public DrinkTemplate
{
public:
    virtual void boildWater()
    {
        cout << "煮山泉水..." << endl;
    }
    virtual void Brew()
    {
        cout << "冲泡茶叶..." << endl;
    }
    virtual void PourInCup()
    {
        cout << "将茶水倒入杯中..." << endl;
    }
    virtual void AddSomething()
    {
        cout << "加两片柠檬..." << endl;
    }
};

void test01()
{
    Coffee *coffee = new Coffee();
    // 父类的方法延迟到子类进行使用
    coffee->Make();
    delete coffee;
    coffee = nullptr;

    cout << "-------------" << endl;

    Tea *tea = new Tea();
    tea->Make();
    delete tea;
    tea = nullptr;
}

int main()
{
    test01();
    system("pause");
    return 0;
}
