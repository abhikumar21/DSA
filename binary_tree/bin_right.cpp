#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <cstdlib> //includes abs(); function
#include <algorithm>  
#include <cmath> // includes log(), root, pow()
#include <map>

// maximum nodes at level l is [2^l] 
//maximum nodes in a tree of height H is [2^H - 1]
//for N nodes, minimum possible height or minimum number of levels are [ log2(N+1) ]
//a binary tree with L leaves has at least  [  log2(N+1)+1 ]  number of levels

using namespace std;




struct node{
    int data;
    struct node* left;
     struct node* right;

     node(int val) {
        data = val;
        left=NULL;
        right=NULL;
     }
};


void hori(struct node* root, map<int, vector<int>> &m1,  map<int, vector<int>> &m2, int hr, int vr) {
  if(root==NULL) {
    return;
  }
    m1[hr].push_back(root->data);
    m2[vr].push_back(root->data);
     hori(root->left, m1, m2, hr-1, vr-1);
     hori(root->right, m1, m2,  hr+1, vr-1);
}

int main() {
  struct node* root= new node(1);
  root->left= new node(2);
  root->right=new node(3);
  root->left->left=new node(4);
  root->left->right=new node(5);

  map<int, vector<int> > m1;
  map<int, vector<int> > m2;

  int hr=0;
  int vr=0;
  hori(root, m1, m2, hr, vr);
   

      
    return 0;
}