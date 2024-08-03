#include <bits/stdc++.h>
using namespace std;


int frogJump(int n, vector<int>& H, int i, int k, vector<int>& dp) {
    if(i<=0) return 0;

    if(dp[i] != -1) return dp[i];
    int mn = INT_MAX;
    for(int j=1;j<=k;j++) {
        if(i-j>=0) {
          int a = abs(H[i]-H[i-j])+frogJump(n, H, i-j, k, dp);    
        //   cout<<mn<<" "<<a<<" "<<i<<" "<<j<<endl;
          mn = min(mn, a);
        }  
    }

    return dp[i]=mn;
}

int main() {
    int n, k;
    cin>>n;
    cin>>k;
    vector<int> heights(n);
    for(int i=0;i<n;i++) {
        cin>>heights[i];
    }

    vector<int> dp(n+1, -1);
    int ans = frogJump(n, heights, n-1, k, dp);
    cout<<ans;

    return 0;
}