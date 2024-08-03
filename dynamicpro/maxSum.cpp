#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }

        int maxi = INT_MIN;
        for(int i=0;i<n;i++) {
            int sum=0;
            for(int j=i;j<n;j++) {
                sum=sum+a[j];
                cout<<sum<<" "<<i<<j<<endl;
                maxi=max(sum, maxi);
            }
            maxi=max(sum, maxi);
        }
        return maxi;

    return 0;
}