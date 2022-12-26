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
struct Node{
    int data;
    struct Node* left;
    struct Node* right;
    Node(int value) {
        data=value;
        left=NULL;
        right=NULL;
    }
};

Node* buildTree(int preorder[], int inorder[], int start, int end) {
static int idx=0;
       if(start>end) {
           return NULL;
       }
           int curr= preorder[idx];
           idx++;
Node* node= new Node(curr);
           if(start==end) {
               return node;
           }
        
       int pos = search(inorder, start, end, curr);
       node->left= buildTree(preorder,inorder, start, pos-1);
       node->right= buildTree(preorder, inorder, pos+1, end);
return node;
}


int search(int inorder[],int start, int end, int curr) {
    for (int i=start; i<=end;i++) {
        if(inorder[i]==curr) {
            return i;
        }
    }
    return  -1;
}
void inorderPrint (Node* root) {
    inorderPrint(root->left);
    cout<<root->data<<" ";
    inorderPrint(root->right);
}

int main() {
   int a1[]={1,2,4,5,3};
   int a2[]={4,2,5,1,3};

Node* root=buildTree(a1, a2, 0, 4);
inorderPrint(root);
 
  
    return 0;
}