class Solution {   
public:
    string frequencySort(string s) {
        string st="";
        map<char, int> m;
        for(int i=0;i<s.length();i++) {
            m[s[i]]++;
        }
        vector<int> v;
        
        for(auto element: m) {
            v.push_back(element.second);
        }
        sort(v.begin(), v.end(), greater<int>());
        // vector<int> :: iterator it;
        // for(auto element: v) {
        //     cout<<element<<" ";
        // }
        //   map<char, int> :: iterator itr1;

        for(int i=v.size();i>0;i--) {
          for(auto element: m) {
              if(i==element.second) {
                 st.append(element.second, element.first);
                 continue;
              }
          }
        }

          return st;
    }
};