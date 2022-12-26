//{ Driver Code Starts
#include<bits/stdc++.h>
        #include <vector>
        #include <stack>
using namespace std;

// } Driver Code Ends


class Solution
{
  public:
    string secFrequent (string arr[], int n)
    {
        stack<string> st;
        for(int i=0;i<n;i++) {
            st.push(arr[i]);
        }
        vector<int> v={0};
       while(!st.empty()){
         for(int i=0;i<n;i++) {
            if(arr[i]==st.top()){
                v[i]++;
                arr[i]="$";
                st.pop();
            }
          }
       }
       int max1=0;
       int max2=0;
       int icurr=-1;
       int iprev=-1;
       
       for(int i=0;i<n;i++) {
           if(arr[i]!="$") {
               if(v[i]>max1) {
                   max2=max1;
                   iprev=icurr;
                   
                   max1=v[i];
                   icurr=i;
                   
               }
           }
       }
       string s=arr[iprev];
       return s;
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        Solution ob;
        cout << ob.secFrequent (arr, n) << endl;
    }
    return 0;
}