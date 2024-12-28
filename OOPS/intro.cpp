#include <bits/stdc++.h>
using namespace std;

class Hero {
    private:

    public:
    
    Hero() { //non - default constructor
        cout<<"Hello"<<endl;
    }

    int health;
    char level;

    char setLevel(char x) {
        level = x;
        return x;
    }

    int getHealth() {
        return health;
    }

    int setHealth(int h) {
        health = h;
        return health;
    }

};

int main() {

    Hero Ram;
    Ram.setHealth(45);
    cout<<"Ram health: "<<Ram.health<<endl;

    Hero *Ramesh = new Hero;
    Ramesh->setHealth(23);
    cout<<"health is: " << (*Ramesh).health<<" ";
    // Ramesh.setHealth(34);
    // cout<<sizeof(Ramesh)<<endl;
    // Ramesh.setLevel('a');
    // cout<<"level is " << Ramesh.level<<endl;


    return 0;
}