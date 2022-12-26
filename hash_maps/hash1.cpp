#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <cstdlib> //includes abs(); function
#include <algorithm>  
#include <cmath> // includes log(), root, pow()
#include <map>

using namespace std;

int main() {
    map<string, int> marksMap;
   marksMap["Harry"] = 98;
   marksMap["Jack"] = 88;
   marksMap["Rohan"] = 59;
    map<string, int> :: iterator itr;
    for (itr=marksMap.begin();itr!=marksMap.end();itr++){
        cout<<(*itr).first<<" "<<(*itr).second<<endl;
    }

map<int, int> gquiz1; 
  
    // insert elements in random order 
    gquiz1.insert(pair<int, int>(1, 40)); 
    gquiz1.insert(pair<int, int>(2, 30)); 
   gquiz1[7]=10;     // another way of inserting a value in a map 
     
 
   
      

    return 0;
}