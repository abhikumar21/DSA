#include <bits/stdc++.h>

using namespace std;


//function overloading
// class Calci {
//     public:  
//     int add(int x, int y, int z=0, int w=1) {
//         return x+y+z+w;  
//     } 
// };

class B{
    public:
    int a=3;
    int b=9;
    
    int add() {
        return a+b;
    }

    void operator+ (B &obj) {
        int value1 = this->a;
        int value2 = obj.a;
        cout<<"print this "<<value1*value2<<endl;
    }

    void operator() () {
        cout<<"main bracked called "<<this->a<<endl;
    }
};

int main() {
    // Calci addIt;
    // cout<<addIt.add(3, 4)<<endl;

    B obj1, obj2;
    obj1.a = 4;
    obj1.b = 2;

    obj2.a = 10;
    obj2.b = 1;

    obj1 + obj2;
    obj1();
   

    return 0;
}