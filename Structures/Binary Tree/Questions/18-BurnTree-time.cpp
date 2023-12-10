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

        BinaryTreeNode(T data) 
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };


#include<bits/stdc++.h>
BinaryTreeNode<int> *createMapping(BinaryTreeNode<int>* root,
        int start,map<BinaryTreeNode<int> *, BinaryTreeNode<int> *> &nodeToParent){
    //creates mapping and returns target node
    BinaryTreeNode<int> *res = NULL;
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    nodeToParent[root] = NULL;
    while(!q.empty()){
        BinaryTreeNode<int> *front = q.front();
        q.pop();

        if(front->data == start){
            res = front;
        }
        if(front->left){
            nodeToParent[front->left] = front;
            q.push(front->left);
        }
        if(front->right){
            nodeToParent[front->right] = front;
            q.push(front->right);
        }
    }
    return res;
}
int burnTree(BinaryTreeNode<int> *root ,
map<BinaryTreeNode<int> *, BinaryTreeNode<int> *> &nodeToParent){
    map<BinaryTreeNode<int> *, bool> visited;
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    visited[root] = true;
    int ans = 0;
    while(!q.empty()){
        bool flag = 0;
        int size = q.size();
        for(int i = 0; i < size; i++){
           BinaryTreeNode<int> *front = q.front();
           q.pop();
           if(front->left && !visited[front->left]){
               flag = 1;
               q.push(front->left);
               visited[front->left] = 1;
           }
           if(front->right && !visited[front->right]){
               flag = 1;
               q.push(front->right);
               visited[front->right] = 1;
           }
           if(nodeToParent[front] && !visited[nodeToParent[front]]){
               flag = 1;
               q.push(nodeToParent[front]);
               visited[nodeToParent[front]] = 1;
           }
       }
       if(flag){
           ans++;
       }
    }
    return ans;
}
int timeToBurnTree(BinaryTreeNode<int>* root, int start)
{
    //step1 : create mapping node to parent 
    //step2 : find target node
    //step3 : find time to burn tree
    int ans;
    map<BinaryTreeNode<int> *, BinaryTreeNode<int> *> nodeToParent;
    BinaryTreeNode<int> *targetNode = createMapping(root,start, nodeToParent);
    ans = burnTree(targetNode, nodeToParent);
    return ans;
}
