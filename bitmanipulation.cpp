#include<iostream>
using namespace std;



//getbit //n=5, 0101
// int getbit(int n, int pos) {
//     return((n&(1<<pos))!=0);   //1<<2=0100    //0001->0100
//   }

// int main() {
// cout<<getbit(5,2);
// return 0;
// }


//////////////////////////////////////////////////////////////////////
//setbit

// int setbit(int n, int pos) {
//     return (n|(1<<pos));
// }

// int main() {
//   cout<<setbit(5,1);  
//   return 0;
// }

////////////////////////////////
//clear bit
// int clearbit(int n, int pos) {
//   return (n&(~(1<<pos)));
// }

// int main() {
//   cout<<clearbit(5,2);  
//   return 0;
// }

//////////////////////
//update bit
int updatebit(int n, int pos, int value) {
int clearing= ~(1<<pos);
n = n & clearing;

}

int main() {
  cout<<updatebit(5,2);  
  return 0;
}





