#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>

using namespace std;

void subseq(int arr,int i,int n) {
    if(i==n) {
        
    }
     cout<<subseq(arr+1,i+1,n);
     cout<<*(arr+i)<<subseq(arr+1,i+1,n);
     
    return;
    }

int main() {
     int n;
     cin>>n;
     int a[n];
     for (int i=0;i<n;i++) {
        cin>>a[i];
     }
     subseq(arr,i,n);

     
return 0;
}