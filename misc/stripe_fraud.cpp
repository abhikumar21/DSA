#include <bits/stdc++.h>
using namespace std;

vector<string> breakWords(string s) {
    vector<string> ans;
    string ss = "";
    for(int i=0;i<s.size();i++) {
        if(s[i]==',') {
            ans.push_back(ss);
            ss="";
            continue;
        }
        ss+=s[i];
    }
    ans.push_back(ss);

    return ans;
}


void fCheck(vector<string> &nfraud, vector<string> &fraud, map<string, float>& thres, 
                      map<string, string>& mcc, int minTran, vector<string>& str, map<string, bool>& isFraud) {

    map<string, int> n;
    map<string, int> c;
    for(auto it: str) {
        vector<string> v = breakWords(it);
            if(v[0]=="DISPUTE") {
                if(n[v[2]]<minTran || ((float)c[v[2]]/(float)n[v[2]])<thres[mcc[v[2]]]) {
                isFraud[v[2]]=false;
            }
            continue;
        }
        n[v[2]]++;
        for(auto idx: fraud) {
            if(v[4]==idx) {
                c[v[2]]++;
                break;
            }
        }
        if(n[v[2]]>=minTran && ((float)c[v[2]]/(float)n[v[2]])>=thres[mcc[v[2]]]) {
            isFraud[v[2]]=true;
        }
    }
    return;
}

int main() {
    vector<string> nfraud = {"approved","inavalid_pin","expired_card"};
    vector<string> fraud = {"do_not_honor","stolen_card","lost_card"};
    map<string, float> thres;
    thres["retail"] = 0.5;
    thres["airline"] = 0.25;
    thres["restaurant"] = 0.8;
    thres["venue"] = 0.35;

    map<string, string> mcc;
    mcc["acct_1"] = "airline";
    mcc["acct_2"] = "venue";
    mcc["acct_3"] = "retail";

    int minTran = 0;

    vector<string> str = {
        "CHARGE,ch_1,acct_1,100,do_not_honor",
        "CHARGE,ch_2,acct_1,200,approved",
        "CHARGE,ch_3,acct_1,300,do_not_honor",
        "CHARGE,ch_4,acct_2,100,lost_card",
        "CHARGE,ch_5,acct_2,200,lost_card",
        "CHARGE,ch_6,acct_2,300,lost_card",
        "CHARGE,ch_9,acct_3,100,approved",
        "CHARGE,ch_9,acct_3,100,approved",
        "CHARGE,ch_7,acct_3,100,lost_card",
        "CHARGE,ch_8,acct_2,200,stolen_card"
    };




    map<string, bool> isFraud;
    fCheck(nfraud, fraud, thres, mcc, minTran, str, isFraud);
    // for(auto it: isFraud) {
    //     cout<<it.first;
    //     cout<<",";
    // }
    map<string, bool> :: iterator idx1;
    idx1 = isFraud.begin();
    map<string, bool> :: iterator idx2;
    idx2 = next(idx1, 0);
    cout<<idx1->first<<" "<<idx2->first<<endl;

    map<string, bool> :: iterator it;
    for(it=isFraud.begin();it!=isFraud.end();it++) {
        cout<<it->first;
        if(next(it) != isFraud.end()) {
            cout<<",";
        }
    }


    return 0;
}