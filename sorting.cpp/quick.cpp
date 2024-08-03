#include <bits/stdc++.h>
using namespace std;

int func(int arr[], int low, int high, vector<vector<int>>& v) {
    int pivot = arr[low];
    int i=low, j=high;
    while(i<j) {
        while(i<=high-1 && arr[i]<=pivot) {
            i++;
        }
        while(j>=0 && arr[j]>pivot) {
            j--;
        }

        if(i<j) {
          vector<int> vp;
          vp.push_back(i);
          vp.push_back(j);
          v.push_back(vp);
          swap(arr[i], arr[j]);
        }
       
    }
    vector<int> vp;
    vp.push_back(low);
    vp.push_back(j);
    v.push_back(vp);
    swap(arr[j], arr[low]);

  return j;
}

void quickSort(int arr[], int low, int high, vector<vector<int>>& v) {
    if(low<high) {
        int pIndex = func(arr, low, high, v);
        quickSort(arr, low, pIndex-1, v);
        quickSort(arr, pIndex+1, high, v);
    }
}

int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    int a[n];
    for(int i=0;i<n;i++) {
        a[i]=arr[i];
    }


    vector<vector<int>> v;
    quickSort(arr, 0, n-1, v);

    for(auto it: v) {
        swap(a[it[0]], a[it[1]]);
    }

    for(int i=0;i<n;i++) {
        cout<<a[i]<<" ";
    }

    return 0;
}