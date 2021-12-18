/*
 * @Description: 
 * @Author: Mr. Lee
 * @Date: 2021-12-16 16:38:10
 * @LastEditTime: 2021-12-16 16:38:11
 * @LastEditors: Mr. Lee
 */
#include <bits/stdc++.h>
using namespace std;

class NewHashMap {
private:
    unordered_map<int, pair<int, int>> ump;
    int all_value;
    unsigned int old_version;
    unsigned int max_version;
public:
    NewHashMap() : all_value(0), old_version(0), max_version(0) {}
    ~NewHashMap() {}

    int Get(int key) {
        if (ump.count(key) != 0) {
            if (ump[key].second > old_version)
                return ump[key].first;
            else
                return all_value;
        } else return -1;     
    }

    void Set(int key, int value) {
        max_version++;
        ump[key] = make_pair(value, max_version);
    }

    void SetAll(int value) {
        max_version++;
        old_version = max_version;
        all_value = value;
    }
};

int main() {
    NewHashMap temp;
    for (int i = 0; i < 10; i++)
        temp.Set(i, i * i);
    for (int i = 0; i < 10; i++)
        cout << temp.Get(i) << ",";
    cout << endl;
    temp.SetAll(500);
    for (int i = 0; i < 10; i++)
        cout << temp.Get(i) << ",";
    cout << endl;
    temp.Set(1, 100);
    for (int i = 0; i < 10; i++)
        cout << temp.Get(i) << ",";
}

