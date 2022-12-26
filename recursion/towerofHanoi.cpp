#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <cstdlib> //includes abs(); function
#include <algorithm>  
#include <cmath> // includes log(), root, pow()
#include <map>


//print instructions
using namespace std;

void toh(int n, int curr,int tar,int help) {

 if(n==0) {
  return;
 }
    toh(n-1, curr, help, tar); //will print instructions to move n-1 disks from curr to target using helper
    cout<<n<<"["<<curr<<"->"<<help<<"]"<<endl;  
    toh(n-1, help, tar, curr);

}

int main() {
  
  int n;
  cin>>n;
  int curr, tar, helper;
  cin>>curr>>tar>>helper;
  toh(n,curr, tar, helper);

    return 0;
}