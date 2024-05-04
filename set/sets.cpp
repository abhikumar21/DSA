
#include <bits/stdc++.h>
// #include <set>
using namespace std;

int main() {
     
     // set => unique elements
     // multiset => can contain non unique elements
     //random access not possible

     set<int> s;
     // insertion : Log(N)
     // deletion : Log(N)
     // upper/lowerBound : log(N)
     // set<int, greater<int>> s; for descending
     s.insert(1);
     s.insert(2);
     s.insert(2);
     s.insert(3);
     s.insert(5);

     for(auto i: s) {
        cout<<i<<" ";
     }
     cout<<endl;
     for(auto i=s.begin();i!=s.end();i++) {
        cout<<*i<<" ";
     }
     cout<<"Size is "<<s.size()<<" ";
        cout<<endl;
    s.erase(2);
    s.erase(s.begin());
    for(auto i=s.rbegin();i!=s.rend();i++) {
       cout<<*i<<" ";
    }  
    cout<<endl;
     

     s.insert(2);
    cout<<*s.lower_bound(2)<<" ";
    cout<<*s.upper_bound(2)<<" ";
    cout<<(s.upper_bound(5) == s.end())<<" ";
    cout<<endl;

    multiset<int> mt;
    mt.insert(1);
    mt.insert(2);
    mt.insert(2);
    for(auto i=mt.begin();i!=mt.end();i++) {
        cout<<*i<<" ";
     }
     cout<<endl;

  
    return 0;
}