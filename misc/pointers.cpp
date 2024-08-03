#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }

    int *pt = arr;
    cout<<pt+2<<"*pt"<<" "<<arr+2<<"arr"<<" ";

    // int *a=&n;
    // cout<<n<<"n"<<" "<<*a<<"*a"<<" "<<&n<<"&n"<<" "<<a<<"a"<<endl;

    return 0;
}