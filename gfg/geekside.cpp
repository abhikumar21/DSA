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
  int n,k;
  cin>>n>>k;
  int a[n];
  deque<int> d;
  for (int i=0;i<n;i++) {
    cin>>a[i];
  }
  int i;
  for(i=0;i<k;i++) {
    while(!d.empty() && a[i]>=d.back()) {
        d.pop_back();
    }
        d.push_back(a[i]);
    
  }
  for(;i<n;i++) {
    cout<<d.front()<<" ";
    
    while(!d.empty() && a[i]>=d.back()) {
        d.pop_back();
    }
        d.push_back(a[i]);
    
    cout<<d.back()<<" ";
  }


    return 0;
}