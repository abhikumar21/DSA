#include <bits/stdc++.h>
using namespace std;


class node{
    public:
    int data;
    node* left;
    node* right;

    node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

node* buildTree(node* root, int i) {
    int n;
    cin>>n;
    root = new node(n);
    // cout<<root->data<<" "<<i;
    
    if(n == -1) {
        return NULL;
    }
    // cout<<"Enter left";
    root->left = buildTree(root->left, i+1);
    // cout<<"Enter right";
    root->right = buildTree(root->right, i+1);

    return root;
}


// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
void levelTraversal(node* root) {
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        node* temp = q.front();
        q.pop();

        if(temp==NULL) {
            cout<<endl;
            if(!q.empty()) {
                q.push(NULL);
            }
        }
        else{
        cout<<temp->data<<" ";

        if(temp->left) {
          q.push(temp->left);
        }
        if(temp->right) {
          q.push(temp->right);
        }
        }
    }
}

// 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1
node* buildFromLevelOrder(node*& root) {
    queue<node*> q;
    cout<<"Enter root"<<endl;
    int data;
    cin>>data;
    root = new node(data);
    q.push(root);

    while(!q.empty()) {
        node* temp = q.front();
        q.pop();

        // cout<<"Enter left for"<<root->data<<endl;
        int leftData;
        cin>>leftData;
        if(leftData != -1) {
            temp->left = new node(leftData);
            q.push(temp->left);
        }
        // cout<<"Enter right for"<<root->data<<endl;
        int rightData;
        cin>>rightData;
        if(rightData != -1) {
            temp->right = new node(rightData);
            q.push(temp->right);
        }
    }
    return root;
}

int main() {

   node* root = NULL;
   buildFromLevelOrder(root);
//    root = buildTree(root, 0);
   levelTraversal(root);

    return 0;
}