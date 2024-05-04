#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n, m, k, H;
        cin>>n>>m>>k>>H;
        int h[n];
        for(int i=0;i<n;i++) {
            cin>>h[i];
        }
        int count=0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if((H-h[j]) == k*(j-i)) {
                    count++;
                }
            }
        }
        cout<<count;
        return 0;
    }
}