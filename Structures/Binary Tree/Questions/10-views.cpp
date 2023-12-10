#include<iostream>
#include<bits/stdc++.h>
using namespace std;



template <typename T>

class BinaryTreeNode 
{
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

//top view
vector<int> getTopView(BinaryTreeNode<int> *root)
{
    vector<int> ans;
    if(root == NULL){
        return ans;
    }
    map<int,int> topNode;
    queue<pair<BinaryTreeNode<int> *, int> > q;
    q.push(make_pair(root, 0));

    while(!q.empty()){
        pair<BinaryTreeNode<int> *, int> temp = q.front();
        q.pop();
        int hd = temp.second;
        BinaryTreeNode<int> *frontNode = temp.first;

//if one value is present for hd do nothing
        if(topNode.find(hd) == topNode.end()){
            topNode[hd] = frontNode->data;
        }
        if(frontNode->left){
            q.push(make_pair(frontNode->left, hd-1));
        }
        if(frontNode->right){
            q.push(make_pair(frontNode->right, hd+1));
        }
    }

    for(auto i: topNode){
        ans.push_back(i.second);
    }
    return ans;
}



//bottom view
vector<int> bottomView(BinaryTreeNode<int> * root){
    vector<int> ans;
    if(root == NULL){
        return ans;
    }
    map<int,int> topNode;
    queue<pair<BinaryTreeNode<int> *, int> > q;
    q.push(make_pair(root, 0));

    while(!q.empty()){
        pair<BinaryTreeNode<int> *, int> temp = q.front();
        q.pop();
        int hd = temp.second;
        BinaryTreeNode<int> *frontNode = temp.first;


        topNode[hd] = frontNode->data;
        if(frontNode->left){
            q.push(make_pair(frontNode->left, hd-1));
        }
        if(frontNode->right){
            q.push(make_pair(frontNode->right, hd+1));
        }
    }

    for(auto i: topNode){
        ans.push_back(i.second);
    }
    return ans;
}


//left view
void solve(BinaryTreeNode<int> *root , vector<int> &ans, int lvl){
    if(root == NULL){
        return;
    }
    // entered new level
    if(lvl == ans.size()){
        ans.push_back(root->data);
    }
    solve(root->left, ans , lvl+1);
    solve(root->right, ans, lvl+1);
}
vector<int> printLeftView(BinaryTreeNode<int> *root)
{
    vector<int> ans;
    if(root == NULL){
        return ans;
    }
    solve(root, ans, 0);
    return ans;
}

//right view
void solve(BinaryTreeNode<int> *root , vector<int> &ans, int lvl){
    if(root == NULL){
        return;
    }
    if(lvl == ans.size()){
        ans.push_back(root->data);
    }
    solve(root->right, ans, lvl+1);
    solve(root->left, ans , lvl+1);
}
vector<int> printRightView(BinaryTreeNode<int>* root) {
    // Write your code here.
    vector<int> ans;
    if(root == NULL){
        return ans;
    }
    solve(root, ans, 0);
    return ans;
}

