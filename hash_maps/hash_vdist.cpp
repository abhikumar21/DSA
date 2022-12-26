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

void vertical_print(node* root, map<int, vector<int> > &m, int hdis ) {
     if(root==NULL) {
        return;
     }
    m[hdis].push_back(root->data);
    vertical_print(root->left, m, hdis-1);
    vertical_print(root->right, m, hdis+1);
     
     
}

int main() {
   struct node* root=new node(8);
    root->left=new node(7);
    root->right=new node(9);
    root->left->left=new node(6);
    root->left->right=new node(2);
    root->right->left=new node(3);
    root->right->right=new node(1);
    map<int, vector<int> > m;
  
   vertical_print(root, m, 0);
   
   map<int, vector<int> > :: iterator itr;
   for(itr=m.begin();itr!=m.end();itr++) {
    for(int i=0;i<(itr->second).size();i++) {
        cout<<(itr->second)[i]<<" ";
    }
    cout<<endl;
   }
  
    return 0;
}