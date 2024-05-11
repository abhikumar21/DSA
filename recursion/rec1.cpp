#include <bits/stdc++.h>
using namespace std;

void printNums(int i, int n) {
    if(i>=n) {
        // cout<<i<<" ";
        return;
    }
    printNums(i+1, n);
    cout<<i<<" ";
    return;
}

int main() {
    //print from 1 to 5
   printNums(1, 5);

    return 0;
}