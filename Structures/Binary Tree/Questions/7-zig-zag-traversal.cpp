//zig zag traversal or spiral traversal
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

vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
    vector<int> result;
    if(root == NULL){
        return result;
    }
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    bool leftToRight = true;
    while(!q.empty()){
        int size = q.size();
        vector<int> ans(size);
//level process
        for(int i = 0; i < size ; i++){
            BinaryTreeNode<int> *temp = q.front();
            q.pop();
//normal insert or reverse insert
            int index = leftToRight ? i : size-i-1;
            ans[index] = temp->data;

            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
        for(auto i: ans){
            result.push_back(i);
        }

        //direction change
        leftToRight = !leftToRight;
    }
    return result;
}
