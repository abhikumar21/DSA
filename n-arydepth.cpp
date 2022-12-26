
// class Solution {
// public:
//     int maxDepth(Node* root) {
//         if(root==NULL) {
//             return 0;
//          }

//          int depth=0;
//          vector<Node*>:: iterator it;

//          for(it=root->children.begin();it!=root->children.end();it++) {
//               depth=max(depth, maxDepth(*it));
//          }
//          return depth+1;
//     }
// };