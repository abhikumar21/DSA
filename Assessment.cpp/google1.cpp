
#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, c;
    bool operator<(const Edge& other) const {
        return c < other.c;
    }
};

int find(vector<int>& parent, int u) {
    if (parent[u] != u) parent[u] = find(parent, parent[u]);
    return parent[u];
}

void unite(vector<int>& parent, vector<int>& rank, int u, int v) {
    int root_u = find(parent, u);
    int root_v = find(parent, v);
    if (root_u != root_v) {
        if (rank[root_u] > rank[root_v]) {
            parent[root_v] = root_u;
        } else if (rank[root_u] < rank[root_v]) {
            parent[root_u] = root_v;
        } else {
            parent[root_v] = root_u;
            rank[root_u]++;
        }
    }
}

long long solve(int n, vector<Edge>& edges) {
    sort(edges.begin(), edges.end());
    vector<int> parent(n + 1), rank(n + 1, 0);
    iota(parent.begin(), parent.end(), 0);
    long long cost = 0;
    int edges_used = 0;
    for (const auto& edge : edges) {
        if (find(parent, edge.u) != find(parent, edge.v)) {
            unite(parent, rank, edge.u, edge.v);
            cost += edge.c;
            edges_used++;
            if (edges_used == n - 1) break;
        }
    }
    return cost;
}


// Break and Add ✅
// Google