#include <bits/stdc++.h>
using namespace std;

class Hero {
    private:
    int health;

    public:
    char level;

    int getHealth() {
        return health;
    }

    int setHealth(int h) {
        health = h;
        return health;
    }

};

int main() {

    Hero Ramesh;
    Ramesh.setHealth(34);
    // cout<<sizeof(Ramesh)<<endl;
    cout<<Ramesh.setHealth(20)<<endl;

    return 0;
}