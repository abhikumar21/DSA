#include <bits/stdc++.h>
using namespace std;

int solve(int n, int a[], int k, int b) {
    if(k<0) {
        return 0;
    }
    if(k==0) {
        return 1;
    }
    int count=0;
    for(int i=1;i<=b;i++) {
       int l=solve(n-i, a, k-a[i], b);
       count+=l;
    }
    
  return count;
}

int main() {
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    int k;
    cin>>k;
    cout<<solve(n, a, k, n)<<endl;
    return 0;
}