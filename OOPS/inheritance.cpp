#include <bits/stdc++.h>

using namespace std;
 

class Human {
    public:
    int height;
    int weight;
    int age;
    string limb = "Hands";

    public:
    int getAge() {
        return this->age;
    }
    int getWeight() {
        return this->weight;
    }
};

class Animal {
    public:
    bool veg=0;
    bool nonVeg=1;
    int brain;
    string limb = "Legs";
};

class Centaur: public Human, public Animal { //multiple inheritance
    public:
    Centaur() {
        cout<<"Welcome to Centaur"<<endl;
    }
};

class Male: public Human {
    public:
    string color;
    Male() {
      cout<<"private Human"<<endl;
    }

    void sleep() {
        cout<<"Male sleeping"<<endl;
    }
};

class Child: public Male {
    public: 
    double price;
    
    Child() {
      cout<<"child is cheap"<<endl;
    }
};


int main() {
    
    // Male Chotu;
    // Child Bunty;

    // cout<<"bunty's age is: "<<Bunty.getAge()<<endl;
    // cout<<"age: "<<Chotu.age<<" ";

    Centaur c1;
    cout<<c1.Human::limb<<endl;


    return 0;
}