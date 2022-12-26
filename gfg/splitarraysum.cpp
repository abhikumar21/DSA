//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int splitArray(int arr[] ,int N, int K) {
        
        
        
    
        int j=0;
        for(int i=N-K;i<N;i++) {
        while(j<N-K ) {
            if(arr[i]<=arr[i+1]) {
                arr[i]=arr[i]+arr[j];
                }
                j++;
            }
                if(arr[i]<=arr[i+1]) {
                    i--;
                }
        
         }
    
    sort(arr, arr+N, greater<int>());
    int a=arr[0];
    return a;
    
    
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.splitArray(arr,N,K);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends