#include <iostream>
using namespace std;
 
int main() {
int n;
cin>>n;
cin.ignore();
char arr[n+1];
cin.getline(arr,n+1);
cin.ignore();
int count=0, max=0;
//largest word
int start=0,mx=0;
for (int i=0;i<n;i++) {
    if(arr[i]==' ') {
       count=0;
    }
    else{
        count++;
        if(count==1) {
            start=i;
        }
    }
    if(max<count) {
        max= count;
        mx=start;
    }

}
 cout<<max<<endl;
 for (int i=mx;i<mx+max;i++) {
     cout<<arr[i];
 }
return 0;
}