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

void inorder(TreeNode *root, vector<int> &arr){
    if(root == NULL){
        return;
    }
    inorder(root->left, arr);
    arr.push_back(root->data);
    inorder(root->right, arr);
}
vector<int> merge(vector<int> &arr1, vector<int> &arr2){
    vector<int> ans(arr1.size() + arr2.size());
    int ind1 = 0, ind2 = 0, i = 0;
    while(ind1 < arr1.size() && ind2 < arr2.size()){
        if(arr1[ind1] < arr2[ind2]){
            ans[i++] = arr1[ind1++];
        }else{
            ans[i++] = arr2[ind2++];
        }
    }
    while(ind1 < arr1.size()){
        ans[i++] = arr1[ind1++];
    }
    while(ind2 < arr2.size()){
        ans[i++] = arr2[ind2++];
    }
    return ans;
}
TreeNode *inOrderToBST(int s,int e, vector<int> arr){
    if(s > e){
        return NULL;
    }
    int mid = s +(e-s)/2;
    TreeNode *root = new TreeNode(arr[mid]);
    root->left = inOrderToBST(s,mid-1,arr);
    root->right = inOrderToBST(mid+1,e,arr);
    return root;
}

TreeNode *mergeBST(TreeNode *root1, TreeNode *root2)
{
    //store inorder
    vector<int> in1 , in2, arr;
    inorder(root1, in1);
    inorder(root2,in2);

    //merge two sorted arrays
    arr = merge(in1,in2);

    //inorder to BST
    TreeNode *reslut = inOrderToBST(0, arr.size()-1, arr);
    return reslut;
}