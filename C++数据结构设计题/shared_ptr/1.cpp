/*
 * @Description:
 * @Author: Mr. Lee
 * @Date: 2021-12-13 17:21:02
 * @LastEditTime: 2021-12-13 17:32:29
 * @LastEditors: Mr. Lee
 */

template <typename T>
class Shared_ptr
{
private:
    int *count;
    T *px;

public:
    
    // explicit 关键字 防止隐式转换
    explicit Shared_ptr(T *p = nullptr) : px(p)
    {
        count = new int(1);
    }

    ~Shared_ptr()
    {
        if (--*count == 0)
        {
            delete px;
            delete count;
        }
    }

    Shared_ptr(const Shared_ptr &s) : px(s.px), count(s.count)
    {
        ++*count;
    }

    Shared_ptr &operator=(const Shared_ptr &s)
    {
        if (this != &s)
        {
            px = s.px;
            count = s.count;
            ++*count;
        }
        return *this;
    }
};