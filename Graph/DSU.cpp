#include <bits/stdc++.h>
using namespace std;

// TC of both union & find op: O(4*alpha)~O(4)
// SC : O(n)

class DSU
{
public:
    vector<int> parent, rank;
    DSU(int n)
    {
        parent.resize(n, 0);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }
    int find(int u)
    {
        if (parent[u] == u)
            return u;
        return parent[u] = find(parent[u]);
    }
    bool unionxy(int u, int v)
    {
        int parU = parent[u];
        int parV = parent[v];
        if (parU != parV)
        {
            if (rank[parU] == rank[parV])
                rank[parU]++;
            if (rank[parU] > rank[parV])
            {
                parent[v] = parent[u];
            }
            else
            {
                parent[u] = parent[v];
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