#ifndef TIME_H_
#define TIME_H_

class Time
{
public:
    Time(int minute = 0, int second = 0);
    const Time operator + (const Time &t) const;
    void show();

private:
    int minute;
    int second;
};

#endif