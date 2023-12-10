#include<iostream>
#include<bits/stdc++.h>
using namespace std;
template <typename T>
class BinaryTreeNode {
       public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left){
                delete left;
            }
            if (right){
                delete right;
            }
        }
    };
BinaryTreeNode<int>* solve(vector<int> &preorder, int min, int max , int &i){
    if(i > preorder.size()-1)
        return NULL;
    if(preorder[i] < min || preorder[i] > max)
        return NULL;
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(preorder[i++]);
    root->left = solve(preorder, min, root->data , i);
    root->right = solve(preorder , root->data, max, i);
    return root;
}
BinaryTreeNode<int>* preorderToBST(vector<int> &preorder) {
    int min = INT_MIN, max = INT_MAX, i = 0;
    return solve(preorder , min, max, i);
}