#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    int amt;
    cin>>amt;

    int dp[amt+1];
    dp[0]=1;
    for(int i=0;i<n;i++) {
        for(int j=a[i];j<amt+1;j++) {
            dp[j] += dp[j-a[i]];

        }

    }
    cout<<dp[amt];
    return 0;
}