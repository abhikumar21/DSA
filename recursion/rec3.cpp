#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int power(int x, int n) {
    
 int f;
   if(n==1) {
    return x;
   }
   else if(n%2==0) {
     f = power(x,n/2)*power(x,n/2);
   }
   else if(n%2!=0) {
     f= x*power(x,n/2)*power(x,n/2);
   }
  return f;
}

int main() {
      int x,n;
      cin>>x>>n;
      if(n%2==0) {
      cout<<power(x,n)<<endl;
      }
     


    return 0;
}