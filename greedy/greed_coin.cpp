#include <bits/stdc++.h>
using namespace std;
// minimum num of coins to make x;

int main() {
    queue<int> q;
  int n;
  cin>>n;
  int a[n];
  for (int i=0;i<n;i++) {
    cin>>a[i];
  }
  int x;
  cin>>x;

  sort(a, a+n);
  int count=0;
  while(n>0 || x!=0) {
    if(a[n-1]<=x) {
        x=x-a[n-1];
        q.push(a[n-1]);
        count++;
    }
    else{
        n--;
    }
  }
  cout<<count<<endl;
// while(!q.empty()) {
//     cout<<q.front()<<endl;
//     q.pop();
// }
  
    return 0;
}