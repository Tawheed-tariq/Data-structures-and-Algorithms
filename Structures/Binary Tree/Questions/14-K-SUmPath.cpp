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

void solve(BinaryTreeNode<int> *root, int k , vector<vector<int>> &paths, vector<int> path){
    if(root == NULL)
        return;
    path.push_back(root->data);
    solve(root->left, k , paths , path);
    solve(root->right, k ,paths, path);
    int sum = 0;
    bool possible = false;
    vector<int> res;
    for(int i = path.size() - 1; i >= 0 ; i--){
        sum += path[i];
        res.push_back(path[i]);
        if(sum == k){
            reverse(res.begin(), res.end());
           paths.push_back(res); 
        }
    }
    path.pop_back();
}
vector<vector<int>> kPathSum(BinaryTreeNode<int> *root, int k) {
    vector<vector<int>> paths;
    vector<int> path;
    solve(root, k , paths, path);
    return paths;
}