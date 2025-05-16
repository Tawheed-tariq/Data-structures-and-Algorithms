#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
void leftTraversal(TreeNode<int> *root, vector<int> &ans){
    
    if((root->left == NULL && root->right == NULL) || (root == NULL)){
        return;
    }
    ans.push_back(root->val);
    if(root->left){
        leftTraversal(root->left, ans);
    }
    else{
        leftTraversal(root->right, ans);
    }
}

void leafTraversal(TreeNode<int> *root, vector<int> &ans){
    if(root == NULL){
        return;
    }
    if(root->left == NULL && root->right == NULL){
        ans.push_back(root->val);
        return;
    }
    leafTraversal(root->left, ans);
    leafTraversal(root->right, ans);
}
void rightTraversal(TreeNode<int> *root, vector<int> &ans){
    if((root == NULL) || (root->left == NULL && root->right == NULL)){
        return;
    }

    if(root->right){
        rightTraversal(root->right,ans);
    }else{
        rightTraversal(root->left,ans);
    }
    ans.push_back(root->val);
}

vector<int> boundaryTraversal(TreeNode<int> *root)
{
    vector<int> ans;
    if(root == NULL){
        return ans;
    }
    ans.push_back(root->val);
    if(root->left)
        leftTraversal(root->left,ans);
    if(root->left || root->right)
        leafTraversal(root, ans);
    if(root->right)
        rightTraversal(root->right, ans);
    return ans;
}