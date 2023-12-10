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


pair<int, int> predecessorSuccessor(TreeNode *root, int key)
{
    TreeNode *temp = root, *temp1 = root;
    int pred = -1, succ = -1;
    while(temp != NULL){
        if(temp->data >= key){
            temp= temp->left;
        }else{
            pred = temp->data;
            temp = temp->right;
        }
    }
    while(temp1 != NULL){
        if(temp1->data <= key){
            temp1= temp1->right;
        }else{
            succ = temp1->data;
            temp1 = temp1->left;
        }
    }
    return {pred,succ};
}