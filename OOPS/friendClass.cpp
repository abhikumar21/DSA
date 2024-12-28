#include <bits/stdc++.h>

using namespace std;

class Raman{
    private:
    int age = 22;
    int length = 4;

    protected:
    int radius = 3;

    friend class Chaman;
};

class Chaman{
    public:
    Chaman(Raman& apna) {
       cout<<apna.age<<endl;
    }
};

int main() {

    Raman apna;
    Chaman koiBhi(apna);


    return 0;
}