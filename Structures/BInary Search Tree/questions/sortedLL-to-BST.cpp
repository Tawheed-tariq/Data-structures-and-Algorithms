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


TreeNode* LLToBST(TreeNode *head, int n){
    if(n <= 0 || head == NULL){
        return NULL;
    }

    TreeNode *left = LLToBST(head, n/2);
    TreeNode *root = head;
    root->left = left;
    head = head->right;

    root->right = LLToBST(head, n-n/2 -1);
    return head;
}
