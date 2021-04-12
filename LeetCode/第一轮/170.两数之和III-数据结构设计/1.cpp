#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class towSum
{
private:
    vector<int> s;

public:
    void add(int x)
    {
        s.push_back(x);
    }

    bool find(int target)
    {
        unordered_map<int, int> myMap;
        for (int i = 0; i < s.size(); i++)
            myMap[s[i]] = i;

        for (int i = 0; i < s.size(); i++)
        {
            if (target == s[i])
                return true;
            int other = target - s[i];
            if (myMap.count(other) && myMap[other] - i)
                return true;
        }
        return false;
    }
};

int main(void)
{
    towSum twosum;
    twosum.add(3);
    twosum.add(1);
    twosum.add(2);
    cout << boolalpha << twosum.find(3) << endl;
    cout << boolalpha << twosum.find(6) << endl;
}