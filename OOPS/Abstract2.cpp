#include <bits/stdc++.h>
using namespace std;

class Abstract {
public:
    virtual void display() = 0;
};

class Concrete : public Abstract {
public:
    void display() { cout << "Concrete"; }
};

int main() {
    Concrete obj;
    obj.display();
    return 0;
}
