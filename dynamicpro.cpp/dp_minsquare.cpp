
#include <bits/stdc++.h>
using namespace std;

int sq(int n) {
    if(n==0||n==1||n==2||n==3) {
      return n;
    }
   
   int ans=10000;
   for(int i=1;i*i<=n;i++) {
    ans=min(ans, 1+sq(n-i*i));
   }
    
  return ans;
}

// void sq(int n) {
//   if(n==0) {
//     return;
//   }
//   if(n==1) {
//     cout<<"1"<<" ";
//     return;
//   }
//    int a=sqrt(n);
//    cout<<a<<" ";
//    sq(n-a*a);
   
//    return;
// }



int main() {
  int n;
  cin>>n;
  cout<<sq(n);
  
    return 0;
}