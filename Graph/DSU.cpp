#include <bits/stdc++.h>
using namespace std;

// TC of both union & find op: O(4*alpha)~O(4)
// SC : O(n)

class UnionFind
{
public:
    vector<int> parent;
    vector<int> rank;
    UnionFind(int n)
    {
        parent.resize(n);
        rank.resize(n, 1);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }
    int findPar(int u)
    {
        if (parent[u] = u)
            return u;
        return parent[u] = findPar(parent[u]);
    }
    bool unify(int u, int v)
    {
        int parU = findPar(u);
        int parV = findPar(v);
        if (parU == parV)
            return false;
        if (rank[parU] == rank[parV])
            rank[parU]++;
        if (rank[parU] > rank[parV])
        {
            parent[parV] = parU;
        }
        else if (rank[parU] < rank[parV])
        {
            parent[parU] = parV;
        }
        return true;
    }
};

int main()
{

    return 0;
}