#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;

    int maxi = 0;

    while(n>0) {
        int num = n%10;
        n=n/10;
        maxi = max(num, maxi);
    }

    cout<<maxi<<endl;

    return 0;
}