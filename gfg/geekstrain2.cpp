#include <iostream>

#include <vector>
//includes abs(); function
#include <algorithm>  


using namespace std;

class Solution{
        public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
       int p[2361]={0};
       for(int i=0;i<n;i++)  {
          p[arr[i]]++;
          p[dep[i]]--;
       }
       for(int i=1;i<2361;i++) {
         p[i]=p[i]+p[i-1];
       }
       int mx=p[0];
       for(int i=1;i<2361;i++) {
        mx=max(mx, p[i]);
       }
       return mx;
    }
    
};
  
int main() {
  int t;
  cin>>t;
  while(t--) {
    int n;
    cin>>n;
    int arr[n];
    int dep[n];
    for (int i=0;i<n;i++) {
        cin>>arr[i];
    }
    for (int i=0;i<n;i++) {
        cin>>dep[i];
    }

    Solution ob;
    cout<<ob.findPlatform(arr, dep, n)<<endl;
  }

    return 0;
}