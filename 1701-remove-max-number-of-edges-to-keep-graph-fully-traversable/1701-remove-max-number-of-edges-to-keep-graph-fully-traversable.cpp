 class UnionFind {
public: // code writtne by sunny
    vector<int> parent, rank;

    UnionFind(int size) {
        parent.resize(size);
        rank.resize(size, 0);
        for (int i = 0; i < size; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);  
        }
        return parent[x];
    }
    void unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
};
class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        UnionFind ufAlice(n + 1), ufBob(n + 1);
        int edgesUsed = 0;
        for (const auto& edge : edges) {
            if (edge[0] == 3) {
                if (ufAlice.find(edge[1]) != ufAlice.find(edge[2])) {
                    ufAlice.unionSets(edge[1], edge[2]);
                    ufBob.unionSets(edge[1], edge[2]);
                    edgesUsed++;
                }
            }
        }
        for (const auto& edge : edges) {
            if (edge[0] == 1) {
                if (ufAlice.find(edge[1]) != ufAlice.find(edge[2])) {
                    ufAlice.unionSets(edge[1], edge[2]);
                    edgesUsed++;
                }
            }
        }
        for (const auto& edge : edges) {
            if (edge[0] == 2) {
                if (ufBob.find(edge[1]) != ufBob.find(edge[2])) {
                    ufBob.unionSets(edge[1], edge[2]);
                    edgesUsed++;
                }
            }
        }
        bool isAliceConnected = true, isBobConnected = true;
        for (int i = 1; i <= n; ++i) {
            if (ufAlice.find(i) != ufAlice.find(1)) isAliceConnected = false;
            if (ufBob.find(i) != ufBob.find(1)) isBobConnected = false;
        }
        if (!isAliceConnected || !isBobConnected) return -1;
        return edges.size() - edgesUsed;
    }
};