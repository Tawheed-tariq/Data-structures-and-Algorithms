#include<iostream>
#include<bits/stdc++.h>
using namespace std;

    

class BinaryTreeNode {
    
public :
    int data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;

    BinaryTreeNode(int data) {
    this -> left = NULL;
    this -> right = NULL;
    this -> data = data;
    }
};
void inOrder(BinaryTreeNode *root, vector<int> &arr){
	if(root == NULL)
		return;
	inOrder(root->left, arr);
	arr.push_back(root->data);
	inOrder(root->right, arr);
}
void fillPreOrder(BinaryTreeNode* &root , vector<int> &arr , int &index){
	if(root == NULL)
		return;
	root->data = arr[index++];
	fillPreOrder(root->left, arr, index);
	fillPreOrder(root->right, arr, index);
}
BinaryTreeNode* convertBST(BinaryTreeNode* root)
{
	vector<int> arr;
	int i = 0;
	inOrder(root, arr);
	fillPreOrder(root, arr, i);
	return root;
}