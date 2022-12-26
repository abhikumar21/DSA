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
        int a;
       
    //    vector<int> vct={0};
    int vct[24]={0};
      
       for (int i=0;i<n;i++) {
           int j=1;
           while(dep[i]>arr[i]){
               vct[arr[i]%100]++;
              arr[i]= arr[i]%100 * 100+ 100*j;
              j++;
           }
       }
       sort(0,0+24,greater<int>());
        a=vct[0];
    return a;
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