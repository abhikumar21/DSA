#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;

void num(int n) {
    if(n==0) {
        return;
    }
   cout<<n<<endl;
   num(n-1);
   cout<<n<<endl;
   return;
}

int main() {
    int n;
    cin>>n;
    num(n);
      
    return 0;
}