#include <iostream>

//含有纯虚函数的基类为抽象基类
//面向抽象类编程（面向一套预先定义好的接口编程）

class Figure
{
public:
    virtual void GetArea() = 0; //纯虚函数
};

class Circle : public Figure
{
private:
    float m_r;

public:
    Circle(float r) : m_r(r) {}
    virtual void GetArea()
    {
        std::cout << "The area of the circle is:" << 3.14 * m_r * m_r << std::endl;
    }
};

class Triangle : public Figure
{
private:
    float m_a;
    float m_b;

public:
    Triangle(float a, float b) : m_a(a), m_b(b) {}
    virtual void GetArea()
    {
        std::cout << "The area of the triangle is:" << m_a * m_b / 2 << std::endl;
    }
};

void DisplayArea(Figure *p_figure)
{
    p_figure->GetArea(); //会发生多态
}

int main()
{
    Circle Circle1(2.5);
    Triangle Triangle1(1.2, 3.6);

    DisplayArea(&Circle1);
    DisplayArea(&Triangle1);

    return 0;
}