#include <iostream>
#include <vector>

using namespace std;

class UF
{
private:
    int count;
    int *parent;
    int *size;

public:
    UF(int n)
    {
        this->count = n;
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

        count--;
    }

    bool Connected(int p, int q)
    {
        int rootP = Find(p);
        int rootQ = Find(q);
        return rootP == rootQ;
    }

    int Count()
    {
        return count;
    }
};

int main(void)
{
    UF uf(5);
    uf.Union(0, 1);
    uf.Union(1, 2);
    cout << boolalpha << uf.Connected(0, 2) << endl;
    cout << uf.Count() << endl;
}