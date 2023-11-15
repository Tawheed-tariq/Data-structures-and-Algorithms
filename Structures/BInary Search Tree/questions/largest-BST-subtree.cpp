#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left, *right;
    TreeNode() : data(0), left(NULL), right(NULL) {}
    TreeNode(int x) : data(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};
class info{
    public:
    int max;
    int min;
    bool isBST;
    int size;
};
info solve(TreeNode *root, int &ans){
    if(root == NULL)
        return {INT_MIN, INT_MAX, true, 0};

    info left = solve(root->left, ans);
    info right = solve(root->right, ans);
    info curr;
    curr.size = left.size + right.size +1;
    curr.max = max(root->data, right.max);
    curr.min = min(root->data , left.min);
    if(left.isBST && right.isBST && (root->data > left.max && root->data < right.min)){
        curr.isBST = true;
    }else{
        curr.isBST = false;
    }
    if(curr.isBST){
        ans = max(ans, curr.size);
    }
    return curr;
}
int largestBST(TreeNode * root){
    int ans = 0;
    info temp = solve(root, ans);
    return ans;
}