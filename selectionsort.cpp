
#include <bits/stdc++.h>
using namespace std;



void insertion_sort(int n, int *a) {

    for(int i=1;i<n;i++){
        int current = a[i];
        int j=i-1;
        while(a[j]>current && j>=0) {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=current;
    }
}


void selection_sort(int n, int *a) {

     for (int i=0;i<n-1;i++) {
        for (int j=i+1;j<n;j++) {
            if(a[j]<a[i]) {
                int temp= a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
    return;
}


void bubble_sort(int n, int a[]) {
    while(n--) {
        for(int i=0;i<n-1;i++) {
            if(a[i]>a[i+1]) {
                int temp= a[i];
                a[i]=a[i+1];
                a[i+1]=temp;
            }
        }
    }
    return;
}

int main() {

//selection sort
//find minimum and put it in beginning

    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }

    // selection_sort(n, a);
    // bubble_sort(n, a);
    insertion_sort(n, a);

      for(int i=0;i<n;i++) {
        cout<<a[i]<<" ";
    }
    cout<<endl;
   
 return 0;

}