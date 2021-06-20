/*
 * @Description: 1600. 皇位继承顺序。
 * @Author: Mr. Lee
 * @Date: 2021-06-20 10:57:09
 * @LastEditTime: 2021-06-20 12:01:06
 * @LastEditors: Mr. Lee
 */
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <stack>

/*
    使用map模拟继承关系
    set记录死亡人员的名单
*/

using namespace std;

class ThroneInheritance
{
public:
    ThroneInheritance(string kingName)
    {
        king = kingName;
    }

    void birth(string parentName, string childName)
    {
        succeed[parentName].push_back(childName);
    }

    void death(string name)
    {
        deathlist.insert(name);
    }

    vector<string> getInheritanceOrder()
    {
        vector<string> ans;
        dfs(ans);
        return ans;
    }

private:
    string king;
    map<string, vector<string>> succeed;
    set<string> deathlist;

    void dfs(vector<string> &ans)
    {
        stack<string> searchStack;
        searchStack.push(king);
        while (!searchStack.empty())
        {
            string parent = searchStack.top();
            searchStack.pop();

            if (deathlist.find(parent) == deathlist.end())
            {
                ans.push_back(parent);
            }
            
            /* 每一个parent的继任者都是push_back添加的，顺序是反的
            所以此处在反一次，使用的是rbegin()，即可得到正确的继任顺序 */
            for (auto it = succeed[parent].rbegin(); it != succeed[parent].rend(); it++)
            {
                searchStack.push(*it);
            }
        }
    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */

int main()
{
    ThroneInheritance t("king");  // 继承顺序：king
    t.birth("king", "andy");      // 继承顺序：king > andy
    t.birth("king", "bob");       // 继承顺序：king > andy > bob
    t.birth("king", "catherine"); // 继承顺序：king > andy > bob > catherine
    t.birth("andy", "matthew");   // 继承顺序：king > andy > matthew > bob > catherine
    t.birth("bob", "alex");       // 继承顺序：king > andy > matthew > bob > alex > catherine
    t.birth("bob", "asha");       // 继承顺序：king > andy > matthew > bob > alex > asha > catherine
    // 返回 ["king", "andy", "matthew", "bob", "alex", "asha", "catherine"]
    for (auto s : t.getInheritanceOrder())
    {
        cout << s << " ";
    }
    cout << endl;
    t.death("bob"); // 继承顺序：king > andy > matthew > bob（已经去世）> alex > asha > catherine
    // 返回 ["king", "andy", "matthew", "alex", "asha", "catherine"]
    for (auto s : t.getInheritanceOrder())
    {
        cout << s << " ";
    }

    return 0;
}
