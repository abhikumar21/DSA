#include <bits/stdc++.h>
using namespace std;


int fib(int n) {
    if(n==0) {return 0;}
    if(n==1) {return 1;}
   int b=0, c=1;
   int a;
  for(int i=2;i<n;i++) {
   a=b+c;
   int temp=a;
   b=c;
   c=temp;
  }
   return a;
}

int main() {
     int n;
     cin>>n;
     cout<<fib(n)<<endl;
}