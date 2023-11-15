#include<iostream>
#include<bits/stdc++.h>
using namespace std;
template <typename T>
class TreeNode
{
public :
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }

    ~TreeNode() {
        if (left)
            delete left;
        if (right)
            delete right;
    }
};

void inOrder(TreeNode<int>* root,vector<int> &ans){
    if(root == NULL){
        return;
    }
    inOrder(root->left,ans);
    ans.push_back(root->data);
    inOrder(root->right,ans);
}
TreeNode<int> *inOrderToBST(int s,int e, vector<int> arr){
    if(s > e){
        return NULL;
    }
    int mid = s +(e-s)/2;
    TreeNode<int> *root = new TreeNode<int>(arr[mid]);
    root->left = inOrderToBST(s,mid-1,arr);
    root->right = inOrderToBST(mid+1,e,arr);
    return root;
}
TreeNode<int>* balancedBst(TreeNode<int>* root) {
    // Write your code here.
    vector<int> arr;
    inOrder(root,arr);
    return inOrderToBST(0,arr.size()-1, arr);
}