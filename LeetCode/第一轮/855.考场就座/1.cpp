#include <iostream>
#include <set>

using namespace std;

class ExamRoom
{
private:
    int N;
    set<int> seats;

public:
    ExamRoom(int N)
    {
        this->N = N;
    }

    int seat()
    {
        int pre = -1;
        int seat = 0;

        if (!seats.empty())
        {
            int maxDist = *seats.begin();
            for (const auto &s : seats)
            {
                if (pre != -1)
                {
                    int d = (s - pre) / 2;
                    if (d > maxDist)
                    {
                        maxDist = d;
                        seat = pre + d;
                    }
                }
                pre = s;
            }

            if (N - 1 - (*seats.rbegin()) > maxDist)
            {
                seat = N - 1;
            }
        }

        seats.insert(seat);
        return seat;
    }

    void leave(int p)
    {
        seats.erase(p);
    }
};

int main(void)
{
    ExamRoom test(10);
    cout << test.seat() << endl;
    cout << test.seat() << endl;
    cout << test.seat() << endl;
    cout << test.seat() << endl;
    test.leave(4);
    cout << test.seat() << endl;
    return 0;
}