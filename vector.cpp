#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3); //1 2 3
    v.pop_back();  //1 2

    ////
    // for (int i=0;i<v.size();i++) {
    //     cout<<v[i]<<endl;
    // }
    // ////
    // vector<int> :: iterator it;
    // for (it=v.begin();it<v.end();it++) {
    //     cout<<*it<<endl;
    // }

    ////
    //  for (auto element:v) {
    //     cout<<element<<endl;
    //  }

    //  vector<int> v2 (3, 50); //v2= 50 50 50
    //  swap(v,v2);
    //  for (int i=0;i<v.size();i++) {
    //    cout<<v[i]<<endl;
    //  } 
     
     sort(v2.begin(),v2.end());

      
    return 0;
}