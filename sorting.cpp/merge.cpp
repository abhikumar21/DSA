#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int s, int mid, int e) {
    int merged[e-s+1];
    int idx1 = s;
    int idx2 = mid+1;
    int k = 0;

    while(idx1<=mid && idx2<=e) {
        if(arr[idx1]<arr[idx2]) {
            merged[k]=arr[idx1];
            idx1++;
            k++;
        }
        else {
            merged[k]=arr[idx2];
            idx2++;
            k++;
        }
    }
    while(idx1<=mid) {
        merged[k]=arr[idx1];
        idx1++;
        k++;
    }
     while(idx2<=e) {
        merged[k]=arr[idx2];
        idx2++;
        k++;
    }

    for(int i=s, j=0;j<(e-s+1);i++, j++) {  // arr[] cannot use size() or length
        arr[i]=merged[j];
    }
}

void mergeSort(int arr[], int s, int e) {

    if(s<e) {
        int mid = s + (e-s)/2;
        mergeSort(arr, s, mid);
        mergeSort(arr, mid+1, e);

        merge(arr, s, mid, e);
    }
}

int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    mergeSort(arr, 0, n-1);

    for(int i=0;i<n;i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}