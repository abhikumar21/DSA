#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    // string str;
    // string str1(5,'n');
    // cout<<str1<<endl;

////////////////////////////////
    // string str="Apnikaksha";
    // cout<<str;

////////////////////////////////for a line with spaces
    // string str;
    // getline(cin,str);
    // cout<<str<<endl;

///////////////////////////////adding string
    // string str;
    // string s1="fam";
    // string s2="ily";
    // cout<<s1+s2<<endl;
    // s1.append(s2);
    // s2.append(s1);
    //s1.clear();
    // if(s1.empty()) {
    //     cout<<"string is empty"<<endl;
    // }
    // s2.append(s2);
    // cout<<s1<<endl;
    // cout<<s2<<endl;
////////////////////////////compare
// string s1="cd";
// string s2="cd";  
// cout<<s2.compare(s1)<<endl;  //if s2 is greater it shows +ve

///////////////////// erase, find
     // string s1="nincompoop";
    //   s1.erase(3, 3); //(index to be deleted, no of char to be deleted);
    //   cout<<s1<<endl;
    //   cout<<s1.find("com")<<endl;
    //   cout<<s1.insert(2, "lol")<<endl;
    //   cout<<s1.size();
    //   cout<<s1.length();
    //   cout<<s1.substr(3, 2);//position, length

    ////////////////////////numeric string to integer
    // string str="934";
    // int x=stoi(str);
    // cout<<x+2<<endl;
    // cout<<to_string(x)+"2"<<endl;

    /////////////////sorting include <algorithm>
    // string s1="hufeifjsopodf";
    // sort(s1.begin(), s1.end());
    // cout<<s1<<endl;

    ////////////////////////transform
    // string str="hjPfnrLnfej";
    // transform(str.begin(), str.end(), str.begin(), :: toupper);
    // cout<<str<<endl;

    /////////////reverse sort
    string str="48092894";
    sort(str.begin(), str.end(), greater<int>());
    cout<<str<<endl;
    return 0;
}