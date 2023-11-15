#include<iostream>
#include <bits/stdc++.h>
using namespace std;
template <typename T>
    class TreeNode {
    public :
        int data;
        TreeNode *left;
        TreeNode *right;

        TreeNode(int data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
        ~TreeNode() {
            if (left){
            delete left;
            }
            if (right){
            delete right;
            }
        }
    };


void solve(TreeNode<int> *root , map<int,vector<int>> &nodes , int d){
    if(root == NULL){
        return;
    }
    nodes[d].push_back(root->data);

    solve(root->left, nodes , d+1);
    solve(root->right , nodes , d);
}

vector<vector<int>> diagonal(TreeNode<int>* root){
    vector<vector<int> > ans;
    if(root == NULL){
        return ans;
    }

    map<int ,vector<int> > nodes;

    solve(root, nodes, 0);
    
    for(auto i: nodes){
        ans.push_back(i.second);
    }
    return ans;
}