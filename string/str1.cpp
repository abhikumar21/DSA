#include <iostream>
#include <string>

using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--) {
        string a,b;
        cin>>a>>b;
        string x=a+b;
        int count[26]{0};
        for (int i=0;i<x.length();i++) {
           count[x[i]-97]++;
           
        }
        int n;
        cin>>n;
        bool flag=1;
        for (int i=0;i<n;i++) {
            string str;
            cin>>str;
            for (int j=0;j<str.length();j++) {
                if(count[97-str[j]]>0){
              count[str[j]-97]--;  
                }  
                else if(count[str[j]-97]<=0) {
                    flag=0;
                    break;
                }
         
            }
            }
            
        
       if(flag==1) {
           cout<<"YES"<<endl;
       } 
       else if (flag==0) {
        cout<<"NO"<<endl;
        }
        
    }     
    return 0;
}


