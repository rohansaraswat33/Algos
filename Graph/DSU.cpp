// TC of both union & find op: O(α(N)) where α(N) => inverse Ackermann Constant =>  ~O(4)
// SC : O(n)

#include <iostream>
#include <vector>

using namespace std;

class UnionFind {
public:
    vector<int> parent;
    vector<int> rank;

    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 1);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    // Find with Path Compression
    int findPar(int u) {
        if (parent[u] == u)  // Fixed comparison (==)
            return u;
        return parent[u] = findPar(parent[u]);  // Path compression
    }

    // Union by Rank
    bool unify(int u, int v) {
        int parU = findPar(u);
        int parV = findPar(v);

        if (parU == parV)
            return false; // Already in the same set

        // Union by Rank
        if (rank[parU] > rank[parV]) {
            parent[parV] = parU;
        } else if (rank[parU] < rank[parV]) {
            parent[parU] = parV;
        } else {
            parent[parV] = parU;
            rank[parU]++; // Rank is updated *after* merging
        }
        return true;
    }
};

int main() {
    UnionFind uf(5);

    uf.unify(0, 1);
    uf.unify(1, 2);

    cout << "Find(2): " << uf.findPar(2) << endl;
    cout << "Find(0): " << uf.findPar(0) << endl;

    return 0;
}
