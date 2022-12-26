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

int main() {
    int n;
    cin>>n;
    int a[n];
  for(int i=0;i<n;i++) {
    cin>>a[i];
  }
  int counter=1;
  while(counter<n) {
      for(int i=0;i<n;i++) {
         if(a[i]>a[i+1]) {
         int temp=a[i];
         a[i]=a[i+1];
         a[i+1]=temp;
         }
    }
    counter++;
  }
    for(int i=0;i<n;i++) {
    cout<<a[i]<<" ";
  }

    return 0;
}