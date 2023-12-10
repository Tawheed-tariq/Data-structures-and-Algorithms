#include<iostream>
#include<bits/stdc++.h>
using namespace std;

template <typename T>
class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
};

pair<int,int> solve(BinaryTreeNode<int> *root){
    pair<int,int> ans; // first => on including current node, second => on excluding current node
    if(root == NULL){
        ans = make_pair(0,0);
        return ans;
    }
    pair<int,int> left = solve(root->left);
    pair<int,int> right = solve(root->right);


//include root
    ans.first = root->data + left.second + right.second;
    ans.second = max(left.first, left.second) + max(right.first , right.second);
    return ans;
}

int maxSumOfAdjacentNodes(BinaryTreeNode<int> *root){
    pair<int,int> result = solve(root);
    return max(result.first, result.second);
}