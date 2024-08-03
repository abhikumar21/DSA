#include <bits/stdc++.h>
using namespace std;

int main() {
    int hash[256] = {0};
    int n;
    cin>>n;
    string str;
    cin>>str;

    for(int i=0;i<n;i++) {
        hash[str[i]-'a']++;
    }
    
    while(n--) {
        char c;
        cin>>c;
        cout<<hash[c-'a']<<endl;
    }
    return 0;
}