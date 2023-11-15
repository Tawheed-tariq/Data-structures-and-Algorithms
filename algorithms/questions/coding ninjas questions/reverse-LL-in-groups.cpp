#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//   Definition for singly-linked list.
  class Node {
  public:
      int data;
      Node *next;
      Node() : data(0), next(nullptr) {}
      Node(int x) : data(x), next(nullptr) {}
      Node(int x, Node *next) : data(x), next(next) {}
  };


int lengthOfLinkedList(Node* &head) {
    Node* temp = head;
    int length = 0;
    while(temp) {
        length ++;
        temp = temp -> next;
        }
        return length;
}

Node* kReverse(Node* head, int k) {
    int length = lengthOfLinkedList(head);
    if(head == NULL || k > length) {
        return head;
    }
    Node* prev=NULL;
    Node* curr=head;
    Node* forward=NULL;
    int cnt=0;
    while(curr!=NULL && cnt<k){
        forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
        cnt++;
     }

    if(forward!=NULL){
         head->next=kReverse(forward,k);
    }
    return prev;
}