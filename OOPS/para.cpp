#include <bits/stdc++.h>
using namespace std;

class Hero{
    public:
    int health;
    int age;
    int gender;



    Hero(int health) {
        cout<<"Ramesh is called"<<endl;
        this->health = health;
    }

};


int main() {

    Hero Ramesh(10);
    // cout<<Ramesh.health<<endl;

    //copy constructor
    Hero Batman(Ramesh);
    cout<<Batman.health<<endl;

    // Hero *Suresh = new Hero(12);
    // cout<<Suresh->health<<endl;

    return 0;
}