#include <iostream>
#include <string>


using namespace std;

////////////////////////////string

// void gss(string str, string output) {
//    if(str.length() == 0) {
//     cout<<output<<endl;
//     return;
//    }

//   gss(str.substr(1), output);
//   gss(str.substr(1), output+str[0]);
    
      

//       return;
// }
// int main() {
//       string str;
//       cin>>str;
//       string output= "";

//       gss(str, output);
      
//     return 0;
// }


/////////////////////////////////array

void printit(int *ssa, int cssi) {
  for (int i=0;i<cssi;i++) {
    cout<<ssa[i]<<" ";
  }
  cout<<endl;
}

void subseq(int *a, int n, int ci,int* ssa, int cssi) {
  if(ci>=n) {
    printit(ssa, cssi);
    return;
  }
   
   subseq(a, n, ci+1, ssa, cssi);
   ssa[cssi] = a[ci];
   subseq(a, n, ci+1, ssa, cssi+1);

}


int main() {
  int n;
  cin>>n;
  int arr[n];
  int ssa[n];
  for (int i=0;i<n;i++) {
    cin>>arr[i];
  }
subseq(arr, n, 0, ssa, 0);
return 0;
}