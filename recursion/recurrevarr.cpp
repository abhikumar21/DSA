#include <iostream>

using namespace std;

int maxarr(int arr[], int idx, int b) {
 if(idx==b-1) {

    return arr[idx];
 }
  
     if(arr[idx]>maxarr(arr,idx+1,b)) {

        return arr[idx];
     }
     else{
        return maxarr(arr,idx+1,b);
     }

}

// void revarr(int arr[],int n) {
//     if(n<=0) {
//         return;
//     }
    
//      cout<<*(arr+n-1)<<endl;
//      revarr(arr,n-1);
//      return;

// }
int main() {
    int n;
    cin>>n;
    int a[n];
    for (int i=0;i<n;i++) {
        cin>>a[i];
    }

//     revarr(a,n);
      /////////////////////////////
     cout<<maxarr(a,0,n);
     

    return 0;
}