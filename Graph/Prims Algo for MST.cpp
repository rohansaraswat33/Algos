#include <bits/stdc++.h>
using namespace std;

int primsMST(int V, vector<vector<int>> adj[])
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
    vector<int> vis(V, 0);
    minHeap.push({0, 0});
    int MSTWeight = 0;
    while (!minHeap.empty())
    {
        int wt = minHeap.top().first;
        int node = minHeap.top().second;
        minHeap.pop();
        if (vis[node])
            continue;
        vis[node] = 1;
        MSTWeight += wt;
        for (auto it : adj[node])
        {
            int adjNode = it[0];
            int edgeWt = it[1];
            if (!vis[adjNode])
            {
                minHeap.push({edgeWt, adjNode});
            }
        }
    }
    return MSTWeight;
}

int main()
{

    return 0;
}