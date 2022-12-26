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

void printcomb(string a[], string n, int i) {
        string s=a[i];
     if(i==s.length()-1) {
        for(int i=0;i<s.length();i++) {
         cout<<s[i];
        }
        return;
     }
    
    printcomb(a, n+'1', i+1 );
    return;
}

int main() {
      string a[]={".;", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tu", "vwx", "yz"};
      string n;
      cin>>n;

     printcomb(a, n, 0);
 
    return 0;
}