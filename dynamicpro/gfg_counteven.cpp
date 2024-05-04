//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
	public:
	int mod= 1000000007;
	
	long long comb(int n, int i, vector<long long> &fact) {
	    if(n==i || i==0) {
	        return 1;
	    }
	    if(i==1 || i==n-1) {
	        return n;
	    }
	    
	    fact[0]=1;
	    fact[1]=1;
	    for(long long j=2;j<=n;j++)  {
	        fact[j]=j*fact[j-1];
	    }
	    long long num= fact[n]/(fact[n-i]*fact[i]);
	    return num;
	}
	
	
	
	int compute_value(int n)
	{
	    long long sum=0;
	    long long k;
	    long long k2;
	    vector<long long> v(n+1);
	    
	    for(int i=0;i<=n;i++) {
	        v[i]=1;
	    }
	    for(long long i=0;i<=n;i++) {
	       k= comb(n, i, v);
	       k2= k*k;
	        sum=sum+k2;
			cout<<sum<<" ";
	    }
		cout<<sum<<" ";
	    int a=sum%mod;
		return a;
	}
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans = ob.compute_value(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends