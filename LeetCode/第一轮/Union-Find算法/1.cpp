#include <iostream>
#include <vector>

using namespace std;

class UF
{
private:
    int count_;
    vector<int> parent;
    vector<int> size;

public:
    UF(int n)
    {
        this->count_ = n;
        vector<int> parent(n);
        vector<int> size(n);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int find_(int x)
    {
        while (x != parent[x])
        {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }

    void union_(int p, int q)
    {
        int rootP = find_(p);
        int rootQ = find_(q);
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
        count_--;
    }

    bool connected(int p, int q)
    {
        int rootP = find_(p);
        int rootQ = find_(q);
        return rootP == rootQ;
    }

    int count()
    {
        return count_;
    }
};

int main(void)
{
    UF uf(5);
    uf.connected(0, 1);
    uf.connected(1, 2);
    cout << uf.count() << endl;
}