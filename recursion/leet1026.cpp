// 1026. Maximum Difference Between Node and Ancestor




class Solution {
public:



int diffl(TreeNode* root1, TreeNode* root0) {
     if(root1==NULL) {
        return 0;
    }
    int a1=abs(root0->val-root1->val);
    int a=max(a1, (diffl(root1->left, root0), diffr(root1->right, root0)));
    int b,c;
    if(root0->left!=root1 && root0->left!=NULL) {
        b=diffl(root1, root0->left);
    }
     if(root0->right!=root1 && root0->left!=NULL) {
        c=diffl(root1, root0->right);
    }
    int d= max(b, c);
    return max(d, a);
}



int diffr(TreeNode* root1, TreeNode* root0) {
    if(root1==NULL) {
        return 0;
    }
    int a1=abs(root1->val-root0->val);
    int a=max(a1, (diffl(root1->left, root0), diffr(root1->right, root0)));
    int b,c;
    if(root0->left!=root1) {
        b=diffl(root1, root0->left);
    }
     if(root0->right!=root1) {
        c=diffl(root1, root0->right);
    }
    int d= max(b, c);
    return max(d, a);
}


  

    int maxAncestorDiff(TreeNode* root) {
     int a= diffl(root->left, root);
     int b=  diffr(root->right, root);

     return max(a, b);

    }

};