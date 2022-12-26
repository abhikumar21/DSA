#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <cstdlib> //includes abs(); function
#include <algorithm>  
#include <cmath> // includes log(), root, pow()
#include <map>

using namespace std;

int maximum(int a[], int n, int i) {
if(i==n-1) {
       return a[n-1];
}
int maxi;

    if(a[i]>maximum(a,n,i+1)) {
        maxi=a[i];
    }
    else{
        maxi=maximum(a,n,i+1);
    }

    return maxi;
}

int main() {
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
   cout<<maximum(a, n, 0)<<endl;
  
    return 0;
}