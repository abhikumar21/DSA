#include <bits/stdc++.h>

using namespace std;

class Hero{
    public:
    int health;
    static int timeToComplete;

    static int func() {  // can access only static members
    //    cout<<timeToComplete<<endl;
       return timeToComplete;
    }
};

int Hero::timeToComplete = 9; //no need to call object
                              // "this" cannot be used

int main() {
     
    // Hero Chotu;
    // Chotu.health;
    cout<<Hero::timeToComplete<<endl; //can access without creating object
    cout<<Hero::func()<<endl;
    // Hero a;
    // a.timeToComplete = 10;
    // cout<<a.timeToComplete<<endl;

    return 0;
}