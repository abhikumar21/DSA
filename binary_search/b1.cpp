#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    //array must be sorted
    int* lb = lower_bound(arr, arr+n, 7);  //returns pointer
    int index = lb-arr;
    cout<<*lb<<endl;

    return 0;
}