#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, i;
    cin>>n>>i;
    cout<< ((n&(1<<i)) ? 1 : 0) <<endl;

    return 0;
}