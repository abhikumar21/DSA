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
    node(int val) {
        data=val;
        left=NULL;
        right=NULL;
    }
};

int sumnodes(node* root) {
    if(root==NULL) {
        return 0;
    }
    // if(root->left==NULL && root->right==NULL){
    //  return root->data;
    // }
    return root->data +sumnodes(root->left)+ sumnodes(root->right);
}

int main() {
  struct node* root= new node(1);
  root->left= new node(2);
  root->right=new node(3);
  root->left->left=new node(4);
  root->left->right=new node(5);
  root->right->left=new node(6);
  root->right->right=new node(7);
  cout<<sumnodes(root);



    return 0;
}