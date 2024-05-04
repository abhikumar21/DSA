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

void printlevelorder(node* root) {
    if(root==NULL) {
        return;
    }
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()) {
        node* node=q.front();
        q.pop();
        
            if(node!=NULL) {
                cout<<node->data<<" ";
                if(node->left) {
                    q.push(node->left);
                    
                }
                if(node->right) {
                    q.push(node->right);
                }
            }
            
            else if(!q.empty()) {
                q.push(NULL);
            }
    }
}



int main() {
  struct node* root= new node(1);
  root->left= new node(2);
  root->right=new node(3);
  root->left->left=new node(4);
  root->left->right=new node(5);

  
  printlevelorder(root);

      
    return 0;
}