#include<iostream>
#include<bits/stdc++.h>
using namespace std;
template <typename T>
    class TreeNode
    {
    public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val)
        {
            this->val = val;
            left = NULL;
            right = NULL;
        }
};
//a binary tree is balanced when 
/*
1. left subtree is height balanced 
2. right subtree is height balanced
3. difference between height of left and right subtree is <= 1
*/

pair<bool,int> balanced(TreeNode<int> *root){
    pair<bool, int> ans; // fisrt => balenced , second => height
    if(root == NULL){
        ans = make_pair(true, 0);
        return ans;
    }
    pair<bool, int> left = balanced(root->left);
    pair<bool,int> right = balanced(root->right);
    bool diff = abs(left.second - right.second) <= 1;
    ans.first = left.first && right.first && diff;
    ans.second = max(left.second, right.second) +1;
    return ans;
}
bool isBalancedBT(TreeNode<int>* root){
    return balanced(root).first;
}