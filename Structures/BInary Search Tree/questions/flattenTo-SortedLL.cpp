#include<iostream>
#include<bits/stdc++.h>
using namespace std;
template <typename T>
class TreeNode {
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
        if(left)
            delete left;
        if(right)
            delete right;
    }
};

void inOrder(TreeNode<int>* root,vector<TreeNode<int> *> &ans){
    if(root == NULL){
        return;
    }
    inOrder(root->left,ans);
    ans.push_back(root);
    inOrder(root->right,ans);
}

TreeNode<int>* flatten(TreeNode<int>* root)
{
    vector<TreeNode<int> *> arr;
    inOrder(root,arr);
    TreeNode<int> *ans = arr[0];
    int i = 0;
    for(i = 0 ; i< arr.size()-1 ; i++){
        arr[i]->left = NULL;
        arr[i]->right = arr[i+1];
    }
    arr[i]->left = NULL;
    arr[i]->right = NULL;
    return ans;
}
