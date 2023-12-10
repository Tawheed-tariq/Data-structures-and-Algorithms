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

BinaryTreeNode<int>* lcaOfThreeNodes(BinaryTreeNode<int>* root, int node1, int node2, int node3) {
    //base case
	if(root == NULL){
		return NULL;
	}
	if(root->data == node1 || root->data == node2 || root->data == node3){
		return root;
	}
	BinaryTreeNode<int> *leftAns = lcaOfThreeNodes(root->left, node1, node2,node3);
	BinaryTreeNode<int> *rightAns = lcaOfThreeNodes(root->right , node1, node2, node3);

	if(leftAns == NULL && rightAns == NULL){
		return NULL;
	}else if(leftAns != NULL && rightAns == NULL){
		return leftAns;
	}else if(leftAns == NULL && rightAns != NULL){
		return rightAns;
	}else{
		return root;
	}
}