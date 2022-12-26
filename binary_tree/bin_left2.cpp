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

void rightview(node* root) {
if(root==NULL) {
    return;
}
    queue<node*> q;
    q.push(root);

    while(!q.empty()) {
        int n=q.size();
        for(int i=0;i<n;i++) {
            node* curr=q.front();
            q.pop();
        }
    }

}


int main() {
  struct node* root= new node(1);
  root->left= new node(2);
  root->right=new node(3);
  root->left->left=new node(4);
  root->left->right=new node(5);

  
  rightview(root);

      
    return 0;
}