#include <string>
#include <iostream>
#include <stack>
#include <map>
#include <vector>
#include <cstdlib> //includes abs(); function
#include <algorithm>  
#include <math.h> // includes log(), root, pow()

using namespace std;

// input
// 1
// 7
// 2 3 9 2 4 2 3


// int main() {
//     int t;
//     cin>>t;

//     while(t--) {
//         int n;
//         cin>>n;
//         int a[n];
//         for (int i=0;i<n;i++) {
//             cin>>a[i];
//         }
//         int v[n]{1};
//         int flag[n]{1};
//                                      //currently not working
//         for (int i=0;i<n;i++) {
//             for (int j=i+1;j<n;j++) {
                
//                 if(a[i]==a[j] && flag[i]==1) {
//                     v[i]++;
//                     flag[j]=0;
//                 }
//             }
//         }
//         for (int i=0;i<n;i++) {
//         cout<<a[i]<<" "<<v[i]<<endl;
//     }
           
//     }
      
//     return 0;
// }

int main() {
     int t;
    cin>>t;

    while(t--) {
        int n;
        cin>>n;
        map<int, int> m;
        for (int i=0;i<n;i++)  {
            int x;
            cin>>x;
            m[x]++;

        }
        map<int, int> :: iterator itr;
        for(auto element : m) {
            cout<<element.first<<" "<<element.second<<endl;
        }
    }

    return 0;
}