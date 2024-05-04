#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int s, int mid, int e) {
    int n1=mid-s+1;
    int n2=e-mid;

    int a[n1];
    int b[n2];

    for(int i=0;i<n1;i++) {
        a[i]=arr[s+i];
    }
    for(int i=0;i<n2;i++) {
        b[i]=arr[mid+1+i];
    }

    int i=0, j=0, k=s;
    while(i<n1 && j<n2) {
        if(a[i]<b[j]) {
            arr[k]=a[i];
            k++;
            i++;
        }
        else{
            arr[k]=b[j];
            k++;
            j++;
        }
    }
    while(i<n1) {
        arr[k]=a[i];
        k++;
        i++;
    }
    while(j<n2) {
        arr[k]=b[j];
        k++;
        j++;
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