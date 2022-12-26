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
        data = val;
        left=NULL;
        right=NULL;
     }
};

int sumatK(Node* root, int k) {
    if(root==NULL) {
        return -1;
    }
}

int main() {
  struct node* root= new node(1);
  root->left= new node(2);
  root->right=new node(3);
  root->left->left=new node(4);
  root->left->right=new node(5);
  root->right->left=new node(6);
  root->right->right=new node(7);
sumatK(root, 5);
      
    return 0;
}