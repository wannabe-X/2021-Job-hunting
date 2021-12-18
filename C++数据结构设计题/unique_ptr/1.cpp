/*
 * @Description:
 * @Author: Mr. Lee
 * @Date: 2021-12-16 16:48:25
 * @LastEditTime: 2021-12-16 16:51:18
 * @LastEditors: Mr. Lee
 */
template <typename T>
class Unique_ptr
{
private:
    T *mPtr;

public:
    explicit Unique_ptr(T *p = nullptr) : mPtr(p) {}

    ~Unique_ptr()
    {
        if (mPtr)
            delete mPtr;
    }

    Unique_ptr(const Unique_ptr &up) = delete;

    Unique_ptr &operator=(const Unique_ptr &up) = delete;

    Unique_ptr(const Unique_ptr &&up) noexcept mPtr(p.mPtr)
    {
        p.mPtr = nullptr;
    }

    Unique_ptr &operator=(const Unique_ptr &&up) noexcept
    {
        if (this != &up)
        {
            if (mPtr)
                delete mPtr;
            mPtr = up.mPtr;
            up.mPtr = nullptr;
        }
        
        return *this;
    }
};