#include <bits/stdc++.h>
using namespace std;

string check(string& str, int n, unordered_map<string, int>& isAvailable) {
        string newStr = "";
        for(int j=0;j<n;j++) {
            if(str[j]>='A' && str[j]<='Z') {
                newStr+= str[j] - 'A' + 'a';
            }
            else if(str[j]>='a' && str[j]<='z') {
                newStr+=str[j];
            }
            if(str[j]==' ' || str[j]==',' || str[j]=='&') {
                //do nothing
            }
        }
        if(isAvailable[newStr]==1) {
            isAvailable[newStr]=0; 
        }
        else {
            isAvailable[newStr]=1;
        }
    return newStr;
}

int main() {

    // string database[5] = {"Leetcode", "Neet", "IITKAnpur", "HelloIITK", "DairyMilk"}; //size() is not defined for this
    vector<string> database = {
        "acct_123|Llama  , Inc.",
        "acct_121|lla ma, inc.",
        "acct_456|The, LLama, LLC",
        "acct_789|Llama & Friend, LLC",
        "acct_321|Llama   And Friend, Inc.",
        "acct_654|Llama The Friend, LLC.",
        "acct_987|And Llama Friend, Inc."
    };

    int n = database.size();
    unordered_map<string, int> mp;
    for(auto it: database) {
        int size = it.find('|');
        string account = it.substr(0, size);
        string name = it.substr(size+1);

        string newStr = check(name, name.size(), mp);

        cout<<account<<"|"<<mp[newStr]<<endl;
        
    }

    return 0;
}