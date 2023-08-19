#include <bits/stdc++.h>
using namespace std;

// TC of both union & find op: O(4*alpha)~O(4)
// SC : O(n)

class UnionFind
{
public:
    vector<int> parent;
    vector<int> size;
    int maxSize;

    UnionFind(int n)
    {
        parent.resize(n);
        size.resize(n, 1);
        maxSize = 1;
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }

    int find(int x)
    {
        // Finds the root of x
        if (x != parent[x])
        {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    bool unite(int x, int y)
    {
        // Connects x and y
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY)
        {
            if (size[rootX] < size[rootY])
            {
                swap(rootX, rootY);
            }
            parent[rootY] = rootX;
            size[rootX] += size[rootY];
            maxSize = max(maxSize, size[rootX]);
            return true;
        }
        return false;
    }
};

int main()
{

    return 0;
}