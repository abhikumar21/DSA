#include <bits/stdc++.h>
using namespace std;


long long dfs(vector<vector<int>>& adj, vector<int>& A, int K, 
int parent, int node, vector<int>& vis) {

    vis[node]=1;
    long long sum = 0;
    int prev = 0;
    for(auto it: adj[node]) {
        if(!vis[it]) { 
        long long unchanged = A[it]+A[node];
        long long changed = (A[it]^K)+(A[node]^K);
        // cout<<changed<<" "<<unchanged<<endl;
        if(changed>=unchanged) {
            A[node]=A[node]^K;
            A[it]=A[it]^K;
        }
        else {
            //dummy
        }
        sum+=dfs(adj, A, K, parent, it, vis);
        }
    }
    return sum+A[node];
}

long long FindMaximum(int n, const vector<vector<int>>& edges, const vector<int>& A, int K) {
    vector<vector<int>> adj(n+1);
    // cout<<edges.size()<<endl;
    for(int i=0;i<edges.size();i++) {
        int u = edges[i][0]-1;  //0 based indexing
        int v = edges[i][1]-1;
        // cout<<u<<" "<<v<<endl;
        adj[u].push_back(v);
        adj[v].push_back(u);
        // cout<<i<<"h"<<endl;
    }
    
    vector<int> vis(n);
    vector<int> B = A;
    long long val = dfs(adj, B, K, -1, 0, vis);
    return val;
}

int main() {
    int N;
    cin >> N;

    vector<vector<int>> edges(N - 1, vector<int>(2));
    for (int i_edges = 0; i_edges < N - 1; i_edges++) {
        for (int j_edges = 0; j_edges < 2; j_edges++) {
            cin >> edges[i_edges][j_edges];
        }
    }

    vector<int> A(N);
    for (int i_A = 0; i_A < N; i_A++) {
        cin >> A[i_A];
    }

    int K;
    cin >> K;

    long long out_ = FindMaximum(N, edges, A, K);
    cout << out_ << endl;

    return 0;
}
