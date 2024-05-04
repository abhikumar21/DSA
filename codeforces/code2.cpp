#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--) {
       int n;
       cin>>n;
       int a[n];
       map<int, int> ma;
       map<int, int> mb;
       for(int i=0;i<n;i++) {
        cin>>a[i];
       }
       for(int i=0;i<n;i++) {
        if(a[i]%2==0) {
            ma[a[i]]=2;
        }
        else{
            ma[a[i]]=1;
        }
       }
       sort(a, a+n);
       for(int i=0;i<n;i++) {
        if(a[i]%2==0) {
            mb[a[i]]=2;
        }
        else{
            mb[a[i]]=1;
        }
       }
       int flag=1;
       for(int i=0;i<n;i++) {
        if(ma[a[i]]!=mb[a[i]]) {
            cout<<a[i]<<"t";
            flag=0;
        }
       }
      if(flag==1) cout<<"YES";
      else cout<<"NO";

    }
    return 0;
}