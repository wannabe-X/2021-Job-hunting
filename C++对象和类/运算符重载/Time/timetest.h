#ifndef TIME_H_
#define TIME_H_

class Time
{
public:
    Time(int minute = 0, int second = 0);
    const Time add(const Time &t) const;
    void show();

private:
    int minute;
    int second;
};

#endif