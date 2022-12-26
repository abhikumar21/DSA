#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
      string str;
      cin>>str;
      int n=str.length();
      for (int i=0;i<n;i++) {
        for (int j=n-1;j>=i;j--) {
           for (int k=i;k<=j;k++) {
            cout<<str[k];
           }
           cout<<endl;
        }
      }

    return 0;
}