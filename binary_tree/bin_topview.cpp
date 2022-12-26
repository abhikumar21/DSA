#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
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

void leftprint(node *root) {
    if(root==NULL) {
        return;
    }
    deque<int> q;
    leftprint(root->left);
    cout<<root->data<<" ";
}

void rightprint(node *root) {
    if(root==NULL) {
        return;
    }
    deque<int> q;
    cout<<root->data<<" ";
    rightprint(root->left);
    
}


int main() {
    struct node* root=new node(8);
    root->left=new node(7);
    root->right=new node(9);
    root->left->left=new node(6);
    root->left->right=new node(2);
    root->right->left=new node(3);
    root->right->right=new node(1);



    leftprint(root->left);  
    cout<<root->data<<" ";
    rightprint(root->right);

    return 0;
}