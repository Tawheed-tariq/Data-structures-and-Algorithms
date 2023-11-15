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

int heightOfBinaryTree(TreeNode<int> *root)
{
	if(!root){
        return 0;
    }
    int left = heightOfBinaryTree(root->left);
    int right = heightOfBinaryTree(root->right);
    int ans = max(left,right)+1;
    return ans;
}