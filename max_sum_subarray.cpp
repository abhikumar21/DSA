#include <bits/stdc++.h>
using namespace std;

int func(int n, int a[]) {
   int max=0;
    int sum=0;
    for(int i=0;i<n;i++) {
        for(int j=i;j<n;j++) {
           for(int k=i;k<j;k++) {
            sum+=a[k];
           }
            if(max<sum) {
            max=sum;
             }
            // cout<<sum<<"hi"<<" ";
            sum=0;
        }
       
    }
    return max;
}

int funBigOn2(int n, int a[]) {
    int max=0;
    int sum;
    for(int i=0;i<n;i++) {
        sum=0;
        for(int j=i;j<n;j++) {
            //  sum + 1 = a[j] || sum = sum + a[j];
        }
    }
    return 0;
}


int BigOn(int n, int a[]) {
      int sum=0;
        int maxsum = a[0];
        for(int i=0;i<n;i++) {
            sum=sum+a[i];
            maxsum=max(maxsum, sum);
            if(sum<0) {
                sum=0;
            }
        }
        return maxsum;
}

int main() {
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    int max= BigOn(n, a);
    cout<<max<<endl;
 
    return 0;
}