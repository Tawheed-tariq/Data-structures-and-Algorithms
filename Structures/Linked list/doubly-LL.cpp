#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    node *prev;
    int data;
    node *next;
    node(int d){
        this-> data = d;
        this->prev = NULL;
        this->next = NULL;
    }
};
void traverse(node* &);
void insertAtHead(node* &, int);
void insertAtTail(node* &,int);
void insertAfter(node* &, int ,int);
void deleteAtHead(node* &);
void deleteAtTail(node* &);
void deleteAfter(node* &, int);
int main(){
    node *n1 = new node(10);
    node *head = n1;
    insertAtHead(head,20);
    insertAtTail(head,30);
    insertAfter(head,5,10);
    traverse(head);
    deleteAfter(head,20);
    traverse(head);
}




//print all elements of list
void traverse(node* &head){
    if(head == NULL){
        cout << "list is empty" << endl;
    }
    else{
        node *ptr = head;
        while(ptr != NULL){
            cout << ptr-> data << "\t";
            ptr = ptr -> next;
        }
        cout << endl;
    }
}

//insert node at head
void insertAtHead(node* &head, int data){
    node *n,*ptr;
    n = new node(data);
    if(head == NULL){
        head = n;
    }
    else{
        n -> next = head;
        head -> prev = n;
        head = n;
    }
}

//insert at end
void insertAtTail(node* &head, int data){
    node *n, *ptr;
    n = new node(data);
    if(head == NULL){
        head = n;
    }
    else{
        ptr = head;
        while(ptr-> next != NULL){
            ptr = ptr->next;
        }
        n->prev = ptr;
        ptr -> next = n;
    }
}
//insert after a node
void insertAfter(node* &head, int data, int x){
    node *n, *ptr;
    n = new node(data);
    if(head == NULL){
        head = n;
    }
    else{
        ptr = head;
        while(ptr->data != x){
            ptr = ptr->next;
        }
        n->prev = ptr;
        n->next = ptr->next;
        ptr->next = n;
    }
}

//delete node at Head
void deleteAtHead(node* &head){
    node *ptr;
    if(head == NULL){
        cout << "list is empty" << endl;
    }else{
        ptr = head;
        head = head->next;
        delete ptr;
    }
}
//delete at tail
void deleteAtTail(node* &head){
    if(head == NULL){
        cout <<  "list is empty";
    }else if(head->next == NULL){
        node *ptr = head;
        head = NULL;
        delete ptr;
    }else{
        node *ptr = head, *prv;
        while(ptr->next != NULL){
            prv = ptr;
            ptr = ptr->next;
        }
        prv->next = NULL;
        delete ptr;
    }
}
//delete after a node
void deleteAfter(node* &head, int x){
    if(head == NULL){
        cout << "list is empty" << endl;
    }else if(head->next == NULL){
        node *ptr = head;
        head = NULL;
        delete ptr;
    }else{
        node *ptr = head, *after;
        while(ptr->data != x){
            ptr = ptr->next;
        }
        after = ptr->next;
        ptr->next = after->next;
        after->next->prev = ptr;
        delete after;
    }
}