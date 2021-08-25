/*
 * @Description: 抽象工厂模式
 * @Author: Mr. Lee
 * @Date: 2021-08-19 20:51:39
 * @LastEditTime: 2021-08-19 21:28:02
 * @LastEditors: Mr. Lee
 */

#include <vector>
#include <iostream>

using namespace std;

// 抽象苹果
class AbstractApple
{
public:
    virtual void ShowName() = 0;
};

// 中国苹果
class ChinaApple : public AbstractApple
{
public:
    virtual void ShowName()
    {
        cout << "这是中国生产的苹果." << endl;
    }
};

// 美国苹果
class USAApple : public AbstractApple
{
public:
    virtual void ShowName()
    {
        cout << "这是美国生产的苹果." << endl;
    }
};

// 英国苹果
class UKApple : public AbstractApple
{
public:
    virtual void ShowName()
    {
        cout << "这是英国生产的苹果." << endl;
    }
};

// 抽象香蕉
class AbstractBanana
{
public:
    virtual void ShowName() = 0;
};

// 中国香蕉
class ChinaBanana : public AbstractBanana
{
public:
    virtual void ShowName()
    {
        cout << "这是中国生产的苹果." << endl;
    }
};

// 美国香蕉
class USABanana : public AbstractBanana
{
public:
    virtual void ShowName()
    {
        cout << "这是美国生产的苹果." << endl;
    }
};

// 英国香蕉
class UKBanana : public AbstractBanana
{
public:
    virtual void ShowName()
    {
        cout << "这是英国生产的苹果." << endl;
    }
};

// 抽象鸭梨
class AbstractPear
{
public:
    virtual void ShowName() = 0;
};

// 中国鸭梨
class ChinaPear : public AbstractPear
{
public:
    virtual void ShowName()
    {
        cout << "这是中国生产的鸭梨." << endl;
    }
};

// 美国鸭梨
class USAPear : public AbstractPear
{
public:
    virtual void ShowName()
    {
        cout << "这是美国生产的鸭梨." << endl;
    }
};

// 英国香蕉
class UKPear : public AbstractPear
{
public:
    virtual void ShowName()
    {
        cout << "这是英国生产的鸭梨." << endl;
    }
};

// 抽象工厂 针对产品族
class AbstractFactory
{
public:
    virtual AbstractApple *CreateApple() = 0;
    virtual AbstractBanana *CreateBanana() = 0;
    virtual AbstractPear *CreatePear() = 0;
};

// 中国工厂
class ChinaFactory : public AbstractFactory
{
public:
    virtual AbstractApple *CreateApple()
    {
        return new ChinaApple();
    }
    virtual AbstractBanana *CreateBanana()
    {
        return new ChinaBanana();
    }
    virtual AbstractPear *CreatePear()
    {
        return new ChinaPear();
    }
};

// 美国工厂
class USAFactory : public AbstractFactory
{
public:
    virtual AbstractApple *CreateApple()
    {
        return new USAApple();
    }
    virtual AbstractBanana *CreateBanana()
    {
        return new USABanana();
    }
    virtual AbstractPear *CreatePear()
    {
        return new USAPear();
    }
};

// 英国工厂
class UKFactory : public AbstractFactory
{
public:
    virtual AbstractApple *CreateApple()
    {
        return new UKApple();
    }
    virtual AbstractBanana *CreateBanana()
    {
        return new UKBanana();
    }
    virtual AbstractPear *CreatePear()
    {
        return new UKPear();
    }
};

void test01()
{
    AbstractFactory *factory = nullptr;
    AbstractApple *apple = nullptr;
    AbstractBanana *banana = nullptr;
    AbstractPear *pear = nullptr;

    // 中国工厂
    factory = new ChinaFactory();
    apple = factory->CreateApple();
    banana = factory->CreateBanana();
    pear = factory->CreatePear();
    apple->ShowName();
    banana->ShowName();
    pear->ShowName();

    delete pear;
    delete banana;
    delete apple;
    delete factory;
}

int main()
{
    test01();
    return 0;
}
