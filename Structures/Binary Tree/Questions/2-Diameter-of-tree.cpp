#include<iostream>
#include<bits/stdc++.h>
using namespace std;

template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
};

pair<int,int> diameter(TreeNode<int> *root){
    pair<int, int> ans; // first => diameter, second=>height
    if(root == NULL){
        ans = make_pair(0,0);
        return ans;
    }
    pair<int,int> left = diameter(root->left);
    pair<int,int> right = diameter(root->right);
    int op1 = left.first; //diameter of left subtree
    int op2 = right.first; //diameter of right sub tree
    int op3 = left.second + right.second; // height of subtree
    ans.first = max(op1,max(op2,op3));
    ans.second = max(left.second,right.second)+1 ;
    return ans;
}

int diameterOfBinaryTree(TreeNode<int> *root){
    return diameter(root).first;
}