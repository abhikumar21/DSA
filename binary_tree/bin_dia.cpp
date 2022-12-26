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

int cheight(node* root){
    if(root==NULL){
        return 0;
    }
    return max(cheight(root->left), cheight(root->right))+1;
}

int dia(node* root) { 
if(root==NULL) {
    return 0;
}

   int lheight= cheight(root->left);
   int rheight= cheight(root->right);
   int currdia=lheight+rheight+1;

   int ldia=dia(root->left);
   int rdia=dia(root->right);


   return max(currdia, max(ldia, rdia));

}



int main() {
    struct node* root=new node(8);
    root->left=new node(7);
    root->right=new node(9);
    root->left->left=new node(6);
    root->left->right=new node(6);

    cout<<dia(root);
  
 

    return 0;
}