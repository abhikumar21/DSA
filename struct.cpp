#include <iostream>
#include <string>
#include <vector>
#include<stack>
#include <cstdlib> //includes abs(); function
#include <algorithm>  
#include <cmath> // includes log(), root, pow()
#include <map>

using namespace std;

// struct employee
// {
//     int eID;
//     char favchar;
//     float salary;
//     /* data */
// };


// int main() {
//   struct employee Harry;
//   Harry.eID=1;
//   Harry.favchar= 'c';
//   Harry.salary = 120000;

//   cout<<Harry.salary;
      
//     return 0;
// }
/////////////////////////////////////////////////////////////////////

// typedef struct employee
// {
//   int eid;
//   char favchar;
//   float salary;
// }ep;

// int main{
//     ep Harry;
//      Harry.eID=1;
//   Harry.favchar= 'c';
//   Harry.salary = 120000;

//   cout<<Harry.salary;

//   return 0;
// }

///////////////////////////////////////////////////////////////////////


// union money {   //uses one data type at a time
//     int rice;
//     char car;
//     float pounds;
// };

// int main() {
//     union money m1;
//     m1.rice =34;
//     m1.car='c';
//     cout<<m1.rice<<endl;
//     cout<<m1.car;
//     return 0;
// }
/////////////////////////////////////////////////////////////////////

int main() {
    enum meal{ breakfast, lunch, dinner};
    cout<<breakfast<<" "<<lunch<<endl;
    meal m1= breakfast;
    cout<<m1;
 
    return 0;
}