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

int calheight(node* root) {
 if(root==NULL) {
    return 0;
 }

    int lheight=calheight(root->left);
    int rheight=calheight(root->right);
    return max(lheight, rheight) + 1;
}



int main() {
    struct node* root=new node(8);
    root->left=new node(7);
    root->right=new node(9);
    root->left->left=new node(6);
    cout<<calheight(root);
  
 

    return 0;
}