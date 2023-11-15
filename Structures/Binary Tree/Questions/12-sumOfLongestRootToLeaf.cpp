#include<iostream>
#include <bits/stdc++.h>
using namespace std;
template <typename T>
    class TreeNode {
    public :
        int data;
        TreeNode *left;
        TreeNode *right;

        TreeNode(int data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
        ~TreeNode() {
            if (left){
            delete left;
            }
            if (right){
            delete right;
            }
        }
};

void solve(TreeNode<int> *root , int sum , int &maxSum , int len , int &maxLen){
    if(root == NULL){
        if(len > maxLen){
            maxLen = len;
            maxSum = sum;
        }else if(len == maxLen){
            maxSum = max(maxSum , sum);
        }
        return;
    }
        sum += root->data;
        solve(root->left, sum, maxSum, len , maxLen);
        solve(root->right, sum, maxSum, len, maxLen);
}

int sumOfLongestRootToLeafPath(TreeNode<int> *root){
    int sum = 0;
    int maxSum = INT_MIN;
    int len = 0;
    int maxLen = 0;

    solve(root, sum , maxSum , len, maxLen);

    return maxSum;
}
