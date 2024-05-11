#include <bits/stdc++.h>
using namespace std;


int printSum(int n, int sum) {
    sum+=n;
    if(n==1) {
        return sum;
    }
    return printSum(n-1, sum);
}

int main() {
    int sum = printSum(5, 0);
    cout<<sum;

    return 0;
}