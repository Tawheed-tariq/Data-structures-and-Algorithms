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
// approach 1 using vector space
void solve(BinaryTreeNode<int> *root, int targetNodeVal, int k, vector<int> path, int &ancestor){
    if(root == NULL){
        return;
    }
    path.push_back(root->data);
    solve(root->left, targetNodeVal, k , path, ancestor);
    solve(root->right, targetNodeVal, k , path, ancestor);

    if(root->data == targetNodeVal && k < path.size()){
        ancestor =  path[path.size()-k-1];
    }
}
int findKthAncestor(BinaryTreeNode<int> *root, int targetNodeVal, int k) {
    vector<int> path;
    int ancestor = -1;
    solve(root, targetNodeVal, k , path, ancestor);
    return ancestor;
}


//approach 2 
BinaryTreeNode<int> *solve(BinaryTreeNode<int> *root, int targetNodeVal, int &k){
    if(root == NULL){
        return NULL;
    }
    if(root->data == targetNodeVal){
        return root;
    }
    BinaryTreeNode<int> *leftAns = solve(root->left, targetNodeVal, k );
    BinaryTreeNode<int> *rightAns = solve(root->right, targetNodeVal, k);
    if(leftAns != NULL && rightAns == NULL){
        k--;
        if(k <= 0){
            //answer locked
            k = INT_MAX;
            return root;
        }
        return leftAns;
    }
    if(leftAns == NULL && rightAns != NULL){
        k--;
        if(k <= 0){
            k = INT_MAX;
            return root;
        }
        return rightAns;
    }
    return NULL;
}
int findKthAncestor(BinaryTreeNode<int> *root, int targetNodeVal, int k) {
    BinaryTreeNode<int> *ancestor = solve(root, targetNodeVal, k);
    if(ancestor == NULL || ancestor->data == targetNodeVal)
        return -1;
    else
        return ancestor->data;
}