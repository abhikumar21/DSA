
#include <bits/stdc++.h>
// #include <set>
using namespace std;

int main() {
     
     // set => unique elements
     // multiset => can contain non unique elements
     //random access not possible

     // insertion : Log(N)
     // deletion : Log(N)
     // upper/lowerBound : log(N)
     // set<int, greater<int>> s; for descending
    
   //   set<int> s;  //implementation using bst
   multiset<int> s;

    s.insert(1);
    s.insert(2);
    s.insert(2);
    s.insert(3);
   // s.erase(2); //deletes all 2's
   // s.erase(s.find(2)); // deletes only one of the 2's
    for(auto it: s) {
      cout<<it<<" ";
    }
    cout<<endl;

    cout<<*s.upper_bound(2)<<" ";
}