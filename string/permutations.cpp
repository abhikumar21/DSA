//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    //Complete this function
    
    vector<string> permutation(string S)
    {
        string st="";
        vector<string> array;
        if(S.length()==0) {
            array.push_back()
        }
        for(int i=0;i<S.length();i++) {
            
            st+S[i];
            string new=permutation(S.erase(i,1));
            st+new;
        }
        return array;
    }
};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for(string s : vec){
		    cout<<s<<" ";
		}
		cout<<endl;
	
	}
	return 0;
}
// } Driver Code Ends


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Solution{
    public:
    //Complete this function
    void per(vector<char> &s, vector<int>&vis, set<string>&temp, string &str)
    {
        if(str.size() == s.size())
        {
            temp.insert(str);
            return ;
        }
        for(int i = 0; i < s.size(); i++)
        {
            if(vis[i] == 0)
            {
                str.push_back(s[i]);
                vis[i] = 1;
                per(s, vis, temp, str);
                str.pop_back();
                vis[i]= 0;
            }
        }
        // return ;
    }
    
    vector<string> permutation(string S)
    {
        //Your code here
        vector<char>v;
        for(char s: S)
        {
            v.push_back(s);
        }
        set<string>temp;
        vector<int>vis(v.size(), 0);
        string str="";
        per(v,vis,temp,str);
        vector<string>res;
        for(auto it: temp)
        {
            res.push_back(it);
        }
        return res;
        
    }
};


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Solution{
    public:
    //Complete this function
    
    void recursion(string s,int index,int n,vector<string>&ans)
    {
        if(index==n)
        {
            ans.push_back(s);
            return ;
        }
        
        for(int i=index;i<n;i++)
        {
            int temp=s[i];
            s[i]=s[index];
            s[index]=temp;
            recursion(s,index+1,n,ans);
            temp=s[i];
            s[i]=s[index];
            s[index]=temp;
        }
    }
    
    vector<string> permutation(string S)
    {
        vector<string>ans={};
        recursion(S,0,S.length(),ans);
        sort(ans.begin(),ans.end());
        return ans;
    }
};
