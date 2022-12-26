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
  deque<int> q;
  vector<int> ans;
  int n,k;
  int a[n];
  cin>>n>>k;
  for (int i=0;i<n;i++) {
    cin>>a[i];
  }
  for (int i=0;i<k;i++) {
    while(!q.empty() && a[q.back()]<a[i]) {
        q.pop_back();
    }
    q.push_back(i);
  }
  



    return 0;
}