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
    int n;
    cin>>n;
    int a[n];
    for (int i=0;i<n;i++) {
        cin>>a[i];
    }
    map<int, int> m;
    int sum=0;
    m[sum]=1;
    int count=0;
    for(int i=0;i<n;i++) {
        sum+=a[i];
        m[sum]++;
      count=count+m[sum]-1;
        
    }
    cout<<count<<endl;
    return 0;
}