#include <bits/stdc++.h>
using namespace std;

class Hero{
    public:
    int age;
    float gender;

    Hero(int age, float gender) {
        this->age = age;
        this->gender = gender;
    }

    Hero(const Hero& other) {
        this->age = other.age;
        this->gender = other.gender;
    }
};

int main() {
    Hero Ramesh(22, 0.3);
    cout<<Ramesh.age<<endl;

    Hero Suresh(Ramesh);
    Suresh.age = 45;
    cout<<Suresh.age<<endl;

    return 0;
}