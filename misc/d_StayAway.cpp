#include <bits/stdc++.h>
using namespace std;

void solve(int n, int m, int k, int A[]) {

    int notTake = f(n-1, m, k, A);
    int take = f(n-1, m, k, A);

}

int main() {
    int n, m, k;
    cin>>n>>m>>k;
    int A[n];
    for(int i=0;i<n;i++) {
        cin>>A[i];
    }

    string ans = solve(n-1, m, k, A);
    cout<<ans<<endl;

    return 0;
}