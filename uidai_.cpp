#include <bits/stdc++.h>
using namespace std;

// DFS function to calculate subtree sums and minimize the difference
void dfs(int node, int parent, int totalSum, vector<pair<int, int>> tree[], vector<int>& subtree, int& minDiff, int& bestEdgeIndex) {
    int sum = subtree[node]; // Initialize with the current node's value

    for (auto& edge : tree[node]) {
        int neighbor = edge.first;
        int edgeIndex = edge.second;

        if (neighbor != parent) {
            dfs(neighbor, node, totalSum, tree, subtree, minDiff, bestEdgeIndex);
            sum += subtree[neighbor];

            // Calculate the difference when cutting this edge
            int otherSum = totalSum - subtree[neighbor];
            int diff = abs(subtree[neighbor] - otherSum);

            // Update the minimum difference and track the edge index
            if (diff < minDiff || (diff == minDiff && edgeIndex < bestEdgeIndex)) {
                minDiff = diff;
                bestEdgeIndex = edgeIndex;
            }
        }
    }

    subtree[node] = sum; // Update the subtree sum
}

int findMinDifferenceEdge(int vertex[], int edges[][2], int n) {
    int totalSum = 0;
    vector<int> subtree(n, 0);

    // Calculate the total sum of all node values
    for (int i = 0; i < n; i++) {
        subtree[i] = vertex[i];
        totalSum += vertex[i];
    }

    // Construct the tree with edge indices
    vector<pair<int, int>> tree[n];
    for (int i = 0; i < n - 1; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        tree[u].emplace_back(v, i);
        tree[v].emplace_back(u, i);
    }

    int minDiff = INT_MAX;
    int bestEdgeIndex = -1;

    // Perform DFS to calculate subtree sums and find the optimal edge
    dfs(0, -1, totalSum, tree, subtree, minDiff, bestEdgeIndex);

    return bestEdgeIndex; // Return the index of the best edge
}

int main() {
    int n;
    cin >> n;

    int edges[n-1][2];
    for (int i = 0; i < n - 1; i++) {
        cin >> edges[i][0] >> edges[i][1];
        // Convert to 0-based indexing for ease
        edges[i][0]--; 
        edges[i][1]--;
    }

    int vertex[n];
    for (int i = 0; i < n; i++) {
        cin >> vertex[i];
    }

    int bestEdgeIndex = findMinDifferenceEdge(vertex, edges, n);
    cout << bestEdgeIndex + 1 << endl; // Convert to 1-based index for the output

    return 0;
}
