#include<iostream>
#include<bits/stdc++.h>
using namespace std;
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

pair<bool,int> isSum(TreeNode<int> *root){
    pair<bool,int> ans;
    //base case
    if(root == NULL){
        ans = make_pair(true, 0);
        return ans;
    }
    if(root->left == NULL && root->right == NULL){
        ans = make_pair(true, root->val);
        return ans;
    }
    pair<bool,int> left = isSum(root->left);
    pair<bool,int> right = isSum(root->right);
    bool curr = root->val == (left.second + right.second);//check condition of sum tree
    ans.second = left.second + right.second + root->val;
    ans.first = left.first && right.first && curr;
    return ans;
}
bool isSumTree(TreeNode<int> *root)
{
    // Write your code here.
    return isSum(root).first;
}