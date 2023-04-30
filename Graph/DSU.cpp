#include <bits/stdc++.h>
using namespace std;

class DSU
{
public:
    vector<int> parent, rank;
    DSU(int n)
    {
        parent.resize(n, 0);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }
    int find(int x)
    {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }
    bool unionXY(int x, int y)
    {
        int xPar = find(x);
        int yPar = find(y);
        if (xPar != yPar)
        {
            if (rank[xPar] < rank[yPar])
            {
                parent[xPar] = yPar;
                rank[xPar]++;
            }
            else
            {
                parent[yPar] = xPar;
                rank[yPar]++;
            }
            return true;
        }
        return false;
    }
};

int main()
{

    return 0;
}