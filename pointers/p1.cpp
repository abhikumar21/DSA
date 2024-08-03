#include<iostream>
using namespace std;

int main() {

    char val = 'd';
    char* ptr = &val;
    cout<<ptr<<" "<<*ptr<<endl;

    return 0;
}