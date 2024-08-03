#include <bits/stdc++.h>
using namespace std;

int main() {
    list<int> l;
    l.push_back(1);
    l.push_back(3);
    l.push_back(3);
    l.push_back(5);
    
    for(auto it: l) {
        cout<<it<<" ";
    }
    cout<<endl;
    l.remove(3);
    for(auto it: l) {
        cout<<it<<" ";
    }

    return 0;
}