#include <bits/stdc++.h>
using namespace std;

// 1 3 4 1 5

double f(int n, vector<double>& v, int target, int idx) {

    if(target==0 && idx==n) {
        return 0;
    }
    if(idx>n) return INT_MAX;

    double er1 = abs( floor(v[idx]) - v[idx]) + f(n, v, target-floor(v[idx]), idx+1 );
    double er2 = abs( ceil(v[idx]) - v[idx]) + f(n, v, target-ceil(v[idx]), idx+1 ) ;

    return min(er1, er2);
}

int main() {
    int n, target;
    cin>>n>>target;
    vector<double> v(n);
    for(int i=0;i<n;i++) {
        cin>>v[i];
    }
    double ans = f(n, v, target, 0);
    if(ans>INT_MAX) cout<<-1<<endl;
    else cout<<ans<<endl;

    return 0;
}