// maps Insertion => O(log(n));
//      assessing => O(log(n));
//       deletion => O(log(n));


// unordered maps Insertion => O(1);
//                accessing => O(1);
//                 deletion => O(n);


#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <cstdlib> //includes abs(); function
#include <algorithm>  
#include <cmath> // includes log(), root, pow()
#include <map>
#include <unordered_map>

using namespace std;

int main() {
//    map<int, int> m;
//    m[8] = 2;
//    cout<<m[8]+3;

int n;
cin>>n;
int a[n];
for(int i=0;i<n;i++) {
    cin>>a[i];
}
map<int, int> m;
for(int i=0;i<n;i++) {
    m[a[i]]++;
}

map<int, int>:: iterator itr;
  for(auto element:m) {
    cout<<element.first<<" "<<element.second<<endl;
  }

    return 0;
}