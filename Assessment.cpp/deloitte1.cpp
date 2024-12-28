#include <bits/stdc++.h>
using namespace std;

int main() {
    string line;
    getline(cin, line);

    char ch;
    cin>>ch;
    
    vector<string> str;
    string s="";
    for(int i=0;i<line.size();i++) {
        if(line[i]==' ') {
            str.push_back(s);
            s="";
            continue;
        }
        s+=line[i];
    }
    str.push_back(s);
    

    sort(str.begin(), str.end());

    // for(auto it: str) {
    //     cout<<it<<" ";
    // }

    for(int i=0;i<str.size();i++) {
        if(str[i].back()==ch) {
            cout<<str[i]<<" "<<i+1<<endl;
        }
    }


    return 0;
}