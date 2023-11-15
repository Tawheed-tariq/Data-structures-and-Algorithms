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
    
};

void inOrder(BinaryTreeNode<int>* root,vector<int> &ans){
    if(root == NULL){
        return;
    }
    inOrder(root->left,ans);
    ans.push_back(root->data);
    inOrder(root->right,ans);
}
bool twoSumInBST(BinaryTreeNode<int>* root, int target) {
	vector<int> arr;
    inOrder(root,arr);
    int i = 0, j = arr.size()-1,sum = 0;
    while(i < j){
        sum = arr[i] + arr[j];
        if(sum == target){
            return true;
        }else if(sum > target){
            j--;
        }else{
            i++;
        }
    }
    return false;
}