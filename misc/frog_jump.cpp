#include <bits/stdc++.h>
using namespace std;

int func(int n, vector<int> &heights, int k) { //dynamic programming
    vector<int> dp(n, 0);
    dp[0]=0;
    dp[1]=abs(heights[1]-heights[0]);
    
    int num;
    for(int i=2;i<n;i++) {
        int step_j=0;
        for(int j=1;j<=k;j++) {
            if(i-j < 0) step_j = INT_MAX;
            else{
             step_j = abs(heights[i]-heights[i-j]) + dp[i-j];
            }
         num=min(step_j, num);
        }
        dp[i]=num;
    }
    return dp[n-1]; 
}


int frogJump(int n, vector<int> &heights, int k)
{
    return func(n, heights, k);
}

int main() {
    int n;
    cin>>n;
    int k;
    cin>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    int ans = frogJump(n, a, k);

    cout<<ans;

    return 0;
}