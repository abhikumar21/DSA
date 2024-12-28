#include <bits/stdc++.h>

using namespace std;


//function overloading
// class Calci {
//     public:  
//     int add(int x, int y, int z=0, int w=1) {
//         return x+y+z+w;  
//     } 
// };

class Human {
    public:
    void sound() {
        cout<<"speak"<<endl;
    }
};

class Animal : public Human {
    public: 
    void sound() {
        cout<<"Bark"<<endl;
    }
};

int main() {
    
   Animal Dog;
   Dog.sound();

    return 0;
}