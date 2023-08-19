#include <bits/stdc++.h>
using namespace std;

void kruskalsMst()
{

    int e = edges.size();
    sort(edges.begin(), edges.end());
    UnionFind dsu(e);
    int MSTWeight = 0;

    for (auto edge : edges)
    {
        int w = edge[0];
        int u = edge[1];
        int v = edge[2];
        if (dsu.unify(u, v))
            MSTWeight += w;
    }
}

int main()
{

    return 0;
}