#include <bits/stdc++.h>
using namespace std;

void bubbleSort(int arr[], int n) {
    for(int i=n-1;i>=0;i--) {
        for(int j=0;j<i;j++) {
            if(arr[j]>arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
        }
    }    
    return;
}

void insertionSort(int arr[], int n) {
    for(int i=0;i<n;i++) {
        for(int j=i+1;j<n;j++) {
            if(arr[i]>arr[j]) {
                swap(arr[i],arr[j]);
            }
        }
    }
    return;
}

int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    bubbleSort(arr, n);
    // insertionSort(arr, n);

    for(int i=0;i<n;i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}