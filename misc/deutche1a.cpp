#include <bits/stdc++.h>
using namespace std;

long long dfs(vector<vector<int>>& adj, vector<int>& A, int K, int node, int parent) {
    // Calculate the sum of the current subtree if left unchanged
    long long unchanged_sum = A[node];
    // Calculate the sum if we XOR the current node with K
    long long xor_sum = A[node] ^ K;
    // cout<<node<<" "<<A[node]<<endl;

    for (auto child : adj[node]) {
        if (child != parent) {
            long long child_sum = dfs(adj, A, K, child, node);
            // Add child's value to both unchanged and xor sums
            unchanged_sum += child_sum;
            xor_sum += (A[child] ^ K);
        }
    }

    // Set the node value based on which option gives a higher sum
    if (xor_sum > unchanged_sum) {
        A[node] ^= K;
        // Apply XOR to all children
        for (auto child : adj[node]) {
            if (child != parent) {
                A[child] ^= K;
            }
        }
        cout<<node<<" "<<A[node]<<endl;
        return xor_sum;
    } else {
        return unchanged_sum;
    }
}

long long FindMaximum(int n, const vector<vector<int>>& edges, const vector<int>& A, int K) {
    vector<vector<int>> adj(n);
    for (const auto& edge : edges) {
        int u = edge[0] - 1;  // Convert to 0-based indexing
        int v = edge[1] - 1;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vector<int> modified_A = A;
    return dfs(adj, modified_A, K, 0, -1);
}

int main() {
    int N;
    cin >> N;

    vector<vector<int>> edges(N - 1, vector<int>(2));
    for (int i = 0; i < N - 1; ++i) {
        cin >> edges[i][0] >> edges[i][1];
    }

    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    int K;
    cin >> K;

    long long result = FindMaximum(N, edges, A, K);
    cout << result << endl;

    return 0;
}
