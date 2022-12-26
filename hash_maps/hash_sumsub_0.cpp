#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    int a[n];
    for (int i=0;i<n;i++) {
        cin>>a[i];
    }
    map<int, int> m;
    int sum=0;
    int count=0;
    m[sum]=1;
    for(int i=0;i<n;i++) {

      sum+=a[i];
      m[sum]++;
      if(m[sum]>1) {
        count+=m[sum]-1;
      }
      
    }
    cout<<count<<endl;
}