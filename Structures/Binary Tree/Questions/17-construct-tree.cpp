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
// from inorder and preorder
void mapping(vector<int> inorder,map<int,int> &nodeToIndex){
    for(int i = 0; i < inorder.size(); i++){
        nodeToIndex[inorder[i]] = i;
    }
}
TreeNode<int> *solve(vector<int> &inorder, vector<int> &preorder, int &preorderIndex, int s, int e, map<int,int> &nodeToIndex){
    //base case
    if(preorderIndex >= preorder.size() || s > e){
        return NULL;
    }
    int ele = preorder[preorderIndex++];
    TreeNode<int> *temp = new TreeNode<int>(ele);
    int pos = nodeToIndex[ele];
    temp->left = solve(inorder, preorder, preorderIndex, s, pos-1, nodeToIndex);
    temp->right = solve(inorder,preorder, preorderIndex, pos+1, e, nodeToIndex);
    return temp;
}
TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder)
{
	int preorderIndex = 0;
    map<int,int> nodeToIndex;
    //create node to index map
    mapping(inorder, nodeToIndex);
    TreeNode<int> *ans = solve(inorder, preorder, preorderIndex, 0 , inorder.size()-1, nodeToIndex);
    return ans;
}




//from inorder and postorder
void mapping(vector<int> inorder,map<int,int> &nodeToIndex){
    for(int i = 0; i < inorder.size(); i++){
        nodeToIndex[inorder[i]] = i;
    }
}
TreeNode<int> *solve(vector<int> &inorder, vector<int> &postorder, int &postorderIndex, int s, int e, map<int,int> &nodeToIndex){
    //base case
    if(postorderIndex < 0 || s > e){
        return NULL;
    }
    int ele = postorder[postorderIndex--];
    TreeNode<int> *temp = new TreeNode<int>(ele);
    int pos = nodeToIndex[ele];
    //incase of post order and inorder we first build right subTree
    temp->right = solve(inorder,postorder, postorderIndex, pos+1, e, nodeToIndex);
    temp->left = solve(inorder, postorder, postorderIndex, s, pos-1, nodeToIndex);
    return temp;
}
TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &postorder)
{
	int postorderIndex = postorder.size()-1;
    map<int,int> nodeToIndex;
    //create node to index map
    mapping(inorder, nodeToIndex);
    TreeNode<int> *ans = solve(inorder, postorder, postorderIndex, 0 , inorder.size()-1, nodeToIndex);
    return ans;
}