/*
 * @Description:
 * @Author: Mr. Lee
 * @Date: 2021-12-13 10:16:20
 * @LastEditTime: 2021-12-13 11:47:19
 * @LastEditors: Mr. Lee
 */

#include <iostream>
#include <vector>

using namespace std;

class Bitmap
{
public:
    Bitmap(int range)
    {
        v.resize(range / 32 + 1);
    }
    
    ~Bitmap() {}

    void set(int value)
    {
        int index = value / 32;
        int offset = value % 32;
        v[index] |= (1 << offset);
    }

    void reset(int value)
    {
        int index = value / 32;
        int offset = value % 32;
        v[index] &= ~(1 << offset);
    }

    bool contains(int value)
    {
        int index = value / 32;
        int offset = value % 32;
        return v[index] & (1 << offset);
    }

private:
    vector<int> v;
};

int main()
{
    Bitmap bit_map(20);
    for (int i = 0; i < 20; i += 2)
        bit_map.set(i);
    
    for (int i = 0; i < 20; i++)
        if (bit_map.contains(i))
        {
            cout << i << " :exist!" << endl;
            bit_map.reset(i);
        }
        else
            cout << i << " :not exist!" << endl;

    cout << "reset_result: " << endl;
    for (int i = 0; i < 20; i++)
        if (bit_map.contains(i))
            cout << i << " :exist!" << endl;
        else
            cout << i << " :not exist!" << endl;
    
    return 0;
}