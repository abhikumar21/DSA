#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <cstdlib> //includes abs(); function
#include <algorithm>  
#include <cmath> // includes log(), root, pow()
#include <map>

using namespace std;

class employee
{
private:
    int a,b,c;
public:
    int d, e;

void get() {
    cout<<a<<endl;
    cout<<b<<endl;
    cout<<c<<endl;
    cout<<d<<endl;
    cout<<e<<endl;

}
    void set(int a1, int b1, int c1)  {
        a=a1;
        b=b1;
        c=c1;
    }
};



int main() {
  employee harry;
  harry.e=20;
  harry.d=34;
//   harry.a=29;      //private
  harry.set(1,2,4);
  harry.get();

      
    return 0;
}