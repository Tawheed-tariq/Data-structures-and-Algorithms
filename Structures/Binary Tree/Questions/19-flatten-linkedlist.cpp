#include<iostream>
#include<bits/stdc++.h>
using namespace std;
template <typename T>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T dat)
    {
        this->data = dat;
        left = NULL;
        right = NULL;
    }
};



void flattenBinaryTree(TreeNode<int>* root)
{
    if(root == NULL){
        return;
    }
    TreeNode<int> *curr = root;
    while(curr != NULL){
        if(curr->left){
            TreeNode<int> *pred = curr->left;
            while(pred->right){
                pred = pred->right;
            }
            pred->right = curr->right;
            curr->right = curr->left;
        }
        curr = curr->right;
    }

    curr = root;
    while(curr != NULL){
        curr->left = NULL;
        curr = curr->right;
    }
}