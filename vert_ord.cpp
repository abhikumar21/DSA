#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <cstdlib> //includes abs(); function
#include <algorithm>  
#include <cmath> // includes log(), root, pow()
#include <map>

using namespace std;

struct node{
    int data;
   struct node* left;
    struct node* right;
    node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};


void vert_ord(struct node* root, int n, map<int, vector<int>> &m) {
    //  map<int, int> m;
    if(root==NULL) {
        return;
    }
   
    m[n].push_back(root->data);
    vert_ord(root->left, n-1, m);
    vert_ord(root->right, n+1, m);
 
}


int main() {
    struct node* root=new node(10);
    root->left=new node(7);
    root->right=new node(4);
    root->left->left=new node(3);
    root->left->right=new node(11);
    root->right->left=new node(14);
    root->right->right=new node(6);
     map<int, vector<int> > m;
    vert_ord(root, 0, m);

    map<int, vector<int>> :: iterator itr;
   for (itr=m.begin(); itr!=m.end();itr++) {
    for(int i=0;i<(itr->second).size();i++) {
        cout<<(itr->second)[i]<<" ";
    }
   }
       cout<<endl;
      return 0;
}