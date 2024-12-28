#include <bits/stdc++.h>
using namespace std;

class Hero {
    public:
    double life=45.3;
    int height=6;  // int(4) + char(1) should be 5 but is 8
    char ch;

    public:
    ~Hero() {
        cout<<"Destructor called"<<endl;
    }
    
};

int main() {
    // Hero Aman;
        
    Hero *Shyam = new Hero();
    cout<<Shyam->life<<endl;
    cout<<(*Shyam).height<<endl;

    delete Shyam; //calling manually for dynamic object

    return 0;
}