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
  //get bit;
  int n;
  cin>>n;
  int count=0;
  for (int i=0;i<32;i++) {
    if((n & (1<<i))!=0) {
      count++;
    //   cout<<(n & (1<<i))<<endl;
    }
  }
  cout<<count<<endl;

    return 0;
}