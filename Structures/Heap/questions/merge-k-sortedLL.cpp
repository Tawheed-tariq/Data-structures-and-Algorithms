#include<iostream>
#include<bits/stdc++.h>
using namespace std;




class Node {
    public:
    int data;
    Node* next;

    Node(int data) {
        next = NULL;
        this->data = data;
    }

    ~Node() {
        if (next != NULL) {
            delete next;
        }
    }
};


class compare{
    public:
    bool operator()(Node *a , Node *b){
        return a->data > b->data;
    }
};
Node* mergeKLists(vector<Node*> &listArray)
{
    priority_queue<Node*, vector<Node*> , compare> minHeap;
    int k = listArray.size();
    if(k == 0)
        return NULL;
    for(int i = 0; i < k; i++){
        if(listArray[i] != NULL){
            minHeap.push(listArray[i]);
        }
    }
    Node *head = NULL, *tail = NULL;
    while(!minHeap.empty()){
        Node *temp = minHeap.top();
        minHeap.pop();
        if(temp->next != NULL){
            minHeap.push(temp->next);
        }
        if(head == NULL){
            head = tail = temp;
        }else{
            tail->next = temp;
            tail = tail->next;
        }
    }
    return head;
}
