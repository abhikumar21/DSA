#include <bits/stdc++.h>
using namespace std;

// Function to check if a number is prime
bool isPrime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) return false;
    }
    return true;
}

// Function to count valid pairs
long long countPair(int N, vector<vector<int>> &edges) {
    // Build adjacency list for the tree
    vector<vector<int>> adj(N + 1);
    for (auto &edge : edges) {
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }

    // Identify primes
    vector<bool> is_prime(N + 1, false);
    for (int i = 1; i <= N; ++i) {
        is_prime[i] = isPrime(i);
    }

    long long total_pairs = 0;

    // DFS function to propagate counts
    function<int(int, int)> dfs = [&](int node, int parent) {
        int prime_count_in_subtree = is_prime[node] ? 1 : 0;

        for (int neighbor : adj[node]) {
            if (neighbor != parent) {
                int prime_count_child = dfs(neighbor, node);

                // Count paths with exactly one prime
                if (prime_count_child == 1) {
                    total_pairs++;
                }

                prime_count_in_subtree += prime_count_child;
            }
        }

        // If current node itself is part of a valid path
        if (prime_count_in_subtree == 1) {
            total_pairs++;
        }

        return prime_count_in_subtree;
    };

    dfs(1, -1);
    return total_pairs / 2; // Each pair is counted twice
}

int main() {
    int N;
    cin >> N;
    vector<vector<int>> edges(N - 1, vector<int>(2));
    for (int i = 0; i < N - 1; ++i) {
        cin >> edges[i][0] >> edges[i][1];
    }

    cout << countPair(N, edges) << endl;
    return 0;
}
