#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin>>n>>m;
    if(m>n) {
        int t=m;
        m=n;
        n=t;
    }
    //n>m;
    while(n%m != 0) {
        int temp=n%m;
        n=m;
        m=temp;
    }
    cout<<m<<endl;
    return 0;
}