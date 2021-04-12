#include <iostream>
#include <vector>

using namespace std;

class UnionFind
{
private:
    int *parent;
    int *size;

public:
    UnionFind(int n)
    {
        parent = new int(n);
        size = new int(n);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int Find(int x)
    {
        while (x != parent[x])
        {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }

    void Union(int p, int q)
    {
        int rootP = Find(p);
        int rootQ = Find(q);

        if (rootP == rootQ)
            return;

        if (size[rootP] > size[rootQ])
        {
            parent[rootQ] = rootP;
            size[rootP] += size[rootQ];
        }
        else
        {
            parent[rootP] = rootQ;
            size[rootQ] += size[rootP];
        }
    }

    bool Connected(int p, int q)
    {
        int rootP = Find(p);
        int rootQ = Find(q);
        return rootP == rootQ;
    }
};

bool equationsPossible(vector<string> &equations)
{
    UnionFind uf(26);

    for (string equ : equations)
    {
        if (equ.at(1) == '=')
        {
            char x = equ.at(0), y = equ.at(3);
            uf.Union(x - 'a', y - 'a');
        }
    }

    for (string equ : equations)
    {
        if (equ.at(1) == '!')
        {
            char x = equ.at(0), y = equ.at(3);
            if (uf.Connected(x - 'a', y - 'a'))
                return false;
        }
    }
    return true;
}

int main(void)
{
    vector<string> equtions = {"b==a", "a==b"};

    bool ans = equationsPossible(equtions);

    cout << boolalpha << ans << endl;
}