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


// maximum levels at level L = 2 raised to power L
// L=3 nodes=8

// maximum nodes in a binary tree of height H = (2 raised to H) - 1
// 1+2+4+8+16+.....

// for N nodes, minimum possible height or minimum levels are l0g base2 (N+1)

/*
          1
         / \
        2   3
       / \ / \
      4  5 6  7    

 */



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

//1. 3. 2. 5. 4.
//      1
//    2    3
//  4  5  6  7
//

void inorder(node* root) {
    stack<node*> st;
    node* temp = root;
    vector<int> v;
    while(true) {
        if(temp!=NULL) {
            st.push(temp);
            temp=temp->left;
        }
        else{
            if(st.empty()==true) break;
            temp = st.top();
            st.pop();
            cout<<temp->data<<" ";
            temp=temp->right;
        }
    }
}

void preorder(node* root) {
    stack<node*> st;
    node* temp;
    st.push(root);
    while(!st.empty()) {
        temp=st.top();
        st.pop();
        cout<<temp->data<<" ";
        if(temp->right != NULL) {
            st.push(temp->right);
        }
        if(temp->left!=NULL) {
            st.push(temp->left);
        }
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


  preorder(root);
    // inorder(root);


      
    return 0;
}