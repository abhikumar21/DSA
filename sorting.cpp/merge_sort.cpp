#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int low, int mid, int high) {
    int temp[high-low+1];
    int left = low;
    int right = mid+1;
    int k=0;
    while(left<=mid && right<=high) {
        if(arr[left] <= arr[right]) {
            temp[k]=arr[left];
            k++;
            left++;
        }
        else{
            temp[k]=arr[right];
            k++;
            right++;
        }
    }
    while(left<=mid) {
        temp[k]=arr[left];
        k++;
        left++;
    }
    while(right<=high) {
        temp[k]=arr[right];
        k++;
        right++;
    }

    for(int i=low;i<=high;i++) {
        arr[i]=temp[i-low];
    }
}

void mergeSort(int arr[], int s, int e) {
    if(s<e) {
        int mid=(s+e)/2;
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