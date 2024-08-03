#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    cout<<sqrt(n)<<endl;
        for (int i = 1; i <= sqrt(n); i++)
        if (n % i == 0) {
            cout << i << " ";
            if (i != n / i)
                cout << n / i << " ";
        }

    cout << "\n";
}