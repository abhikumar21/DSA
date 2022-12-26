#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int factorial(int n) {
    if(n==1) {
        return 1;
    }
    
    int f1=n*factorial(n-1);
    return f1;
}

int main() {
    int n;
    cin>>n;
    int t=factorial(n);
    cout<<t<<endl;
      
    return 0;
}