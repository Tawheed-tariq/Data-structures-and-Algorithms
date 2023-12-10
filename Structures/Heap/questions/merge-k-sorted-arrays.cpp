#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>

class node{
    public:
    int data;
    int row;
    int col;
    node(int data, int row , int col){
        this->data = data;
        this->row = row;
        this->col = col;
    }
};

class compare{
    public:
    bool operator()(node* a , node *b){
        return a->data > b->data;
    }
};

vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
     priority_queue<node* , vector<node*>, compare > minHeap;
     vector<int> ans;
     //insert first element of every array
     for(int i = 0; i < k; i++){
         node *tmp = new node(kArrays[i][0], i, 0);
         minHeap.push(tmp);
     }
     
     while(!minHeap.empty()){
        node *temp = minHeap.top();
        ans.push_back(temp->data);
        minHeap.pop();
        int row = temp->row,  col = temp->col;
        if(col+1 < kArrays[row].size()){
            node *next = new node(kArrays[row][col+1], row , col+1);
            minHeap.push(next);
        }
    }
    return ans;
}
