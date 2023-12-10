#include<iostream>
#include<bits/stdc++.h>
using namespace std;   
    class Node {
        public :

        int data;
        Node *next;

        Node(int data) {
            this -> data = data;
            this -> next = NULL;
        }
    };

Node *floydDetectLoop(Node *head){
    if(head == NULL)
        return NULL;
    Node *slow = head, *fast = head;
    while(slow != NULL && fast != NULL){
        fast = fast->next;
        slow = slow ->next;
        if(fast != NULL){
            fast = fast->next;
        }
        if(slow == fast){
            return slow;
        }
    }
    return NULL;
}

Node *getStartElement(Node *head){
    if(head == NULL)
        return NULL;
    Node *intersection = floydDetectLoop(head), *slow = head;
    if(intersection != NULL){
        while (slow != intersection) {
            slow = slow->next;
            intersection = intersection->next;
        }
        return slow;
    }
    else{
        return NULL;
    }
}

Node *removeLoop(Node *head)
{
    Node *start_loop = getStartElement(head);
    Node *temp = start_loop;
    if(start_loop != NULL){
        while (temp->next != start_loop) {
            temp = temp->next;
        }
        temp->next = NULL;
    }
    return head;
}