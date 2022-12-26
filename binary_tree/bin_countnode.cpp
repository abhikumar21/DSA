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
        data= val;
        left=NULL;
        right=NULL;
    }

};

int count(struct node* root) {
   if(root==NULL) {
  return 0;
   } 
 
//    else ()

    //  i=i+1+count(root->left, i);
    // i=i+1+count(root->right, i);
     return count(root->left)+count(root->right)+1;
}



int main() {
    struct node* root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(2);
    root->left->right=new node(2);

    root->right->left=new node(3);
    // root->right->right=new node(3);

  
  cout<<count(root)<<endl;
      return 0;
}