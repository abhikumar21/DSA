
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int maxCoins(int N, vector<int> &arr) {
        // code here
    }
};



int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        vector<int> arr(N);
        for(int i=0; i<N; i++)
            cin>>arr[i];

        Solution obj;
        cout << obj.maxCoins(N, arr) << endl;
    }
    return 0;
}
