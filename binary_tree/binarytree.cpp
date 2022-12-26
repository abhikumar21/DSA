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

void preorder(struct node* root) {
    if(root==NULL) {
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
    
}

void inorder(struct node* root) {
    if(root==NULL) {
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void postorder(struct node* root) {
     if(root==NULL) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

int main() {
  struct node* root= new node(1);
  root->left= new node(2);
  root->right=new node(3);
  root->left->left=new node(4);
  root->left->right=new node(5);

  preorder(root);
  cout<<endl;
  inorder(root);
  cout<<endl;
  postorder(root);

      
    return 0;
}