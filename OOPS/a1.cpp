#include <bits/stdc++.h>
using namespace std;

// class Base {
// public:
//     void display() { cout << "Base"; }
// };

// class Derived : public Base {
// public:
//      void display() { cout << "Derived"; }
// };

// int main() {
//     Base* obj = new Derived();
//     obj->display();
//     return 0;
// }

class Overload {
public:
    // int add(int a, int b) { 
    //     cout<<"int"<<" ";
    //     return a + b;
    // }
    double add(double a, double b) { 
        cout<<"double"<<" ";
        return a + b; 
    }
};

int main() {
    Overload obj;
    //in c++ cout does print decimal if the num is whole number
    cout << obj.add(1.1, 1) << " " << obj.add(2.4, 3.5);
    return 0;
}

