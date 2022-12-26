//{ Driver Code Starts
//Initial template for C++
#include <queue>
#include <vector>
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *a, int n, int k)
    {
        vector<int> v;
        priority_queue<int> q;
        int i;
        for(i=0;i<k-2;i++) {
            q.push(a[i]);
        }
        i++;
        while(1) {
            if(i>=n) {
                break;
            }
            q.push(a[i]);
            v.push_back(q.top());
            // q.pop(a[i-k]); //only in java
            i++;
        }
        return v;
    }
};

//{ Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, k;
	    cin >> n >> k;
	    
	    int arr[n];
	    for(int i = 0;i<n;i++) 
	        cin >> arr[i];
	    Solution ob;
	    vector <int> res = ob.max_of_subarrays(arr, n, k);
	    for (int i = 0; i < res.size (); i++) 
	        cout << res[i] << " ";
	    cout << endl;
	    
	}
	
	return 0;
}