#include <bits/stdc++.h>
using namespace std;

class Hero {
    private:
    double life=45.3;
    int height=6;  // int(4) + char(1) should be 5 but is 8
    char ch;

    public:
    double getlife() {
        return life;
    }
    
};

int main() {
    Hero Aman;
    cout<<Aman.getlife()<<endl;

    return 0;
}