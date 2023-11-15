#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left, *right;
    TreeNode() : data(0), left(NULL), right(NULL) {}
    TreeNode(int x) : data(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};

//BST to sorted DLL
void ConvertLL(TreeNode *root, TreeNode* &head){
    if(root == NULL){
        return;
    }
    ConvertLL(root->right, head);
    root->right = head;
    if(head)
        head->left = root;
    head = root;
    ConvertLL(root->left , head);
}