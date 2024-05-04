#include <bits/stdc++.h>
using namespace std;



int fib(int n) {
    int dp[n+1];
    
  dp[0]=0;
  dp[1]=1;
    for(int i=2;i<=n;i++) {
        dp[i]=dp[i-1]+dp[i-2];
    }

    return dp[n];
}



// int fib(int n)
// {
//     if(n==0) return 0;
//     if(n==1) return 1;
//     int a=0,b=1, c;

//     for (int i=2;i<=n;i++){
//         c=a+b;
//         int temp=b;
//         b=c;
//         a=temp;
//     }

// return c;
// }

int main() {
    int n;
    cin>>n;
    // vector<int> dp;

    cout<<fib(n);
    return 0;
}

