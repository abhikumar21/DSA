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
   struct node*right;
   node(int val) {
    data=val;
    left=NULL;
    right=NULL;
   }
};

void getverticalorder(struct node* root, int d, map<int, vector<int>> &m) {
    if(root==NULL) {
        return;
    }
    m[d].push_back(root->data);
    getverticalorder(root->left, d-1, m);
    getverticalorder(root->right, d+1, m);

}

int main() {
    struct node* root=new node(1);
  root->left= new node(2);
  root->right=new node(3);
  root->left->left=new node(4);
  root->left->right=new node(5);
  
  map<int, vector<int> > m;
  int hor_dis=0;

  getverticalorder(root, hor_dis, m);
  map<int, vector<int>> ::iterator it;
  for(it =m.begin(); it!=m.end();it++) {
    for(int i=0;i<(it->second).size();i++) {
        cout<<(it->second)[i]<<" ";
    }
    cout<<endl;
  }
  
    return 0;
}
