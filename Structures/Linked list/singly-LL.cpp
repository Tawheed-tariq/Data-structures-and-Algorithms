#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node *next;
    node(int d){
        this->data = d;
        this ->next = NULL;
    }
};
void insertAtHead(node* &, int );
void insertAtTail(node* &, int );
void insertNode(node* &, int ,int);
void traverse(node* &);
void deleteAtHead(node* &);
void deleteAtTail(node* &);
void deleteAfter(node* &,int);

node *reverse(node *head){
    if(head == NULL){
        return NULL;
    }
    else if(head->next == NULL){
        return head;
    }
    node *curr = head, *prev = NULL, *nxt = NULL;
    while(curr != NULL){
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    return prev;
}

int main(){
    node *n1 = new node(10);
    node *head = n1;
    insertAtHead(head,20);
    insertAtTail(head,30);
    insertNode(head,5,20);
    traverse(head);
    cout << endl;
    node *newHead = reverse(head);
    traverse(newHead);
}

//insert node at beginning
void insertAtHead(node* &head, int data){
    node *n = new node(data);
    n -> next = head;
    head = n;
}
//insert node at end
void insertAtTail(node* &head, int data){
    node *n = new node(data);
    if(head == NULL){
        head = n;
    }
    else{
        node *ptr = head;
        while(ptr->next != NULL){
            ptr = ptr->next;
        }
        ptr->next = n;
    }
}
//insert node after specific data
void insertNode(node* &head, int data, int x){
    node *n = new node(data), *ptr = head;
    if(ptr != NULL){
        while(ptr->data != x){
            ptr = ptr -> next;
        }
        n->next = ptr->next;
        ptr->next = n;
    }
    else{
        head = n;
    }
}
//print the linked list
void traverse(node* &head){
    if(head == NULL){
        cout << "list is empty" << endl;
        return;
    }
    node *ptr = head;
    while(ptr != NULL){
        cout << ptr -> data << "\t";
        ptr = ptr -> next;
    }

}
//deletion at beginning
void deleteAtHead(node* &head){
    if(head == NULL){
        cout << "list is empty" << endl;
        return;
    }
    node *ptr = head;
    head = head->next;
    delete ptr;
}

//delete at tail
void deleteAtTail(node* &head){
    if(head == NULL){
        cout << "list is empty";
    }
    else if(head->next == NULL){
        delete head;
        head = NULL;
    }
    else{
        node *ptr = head, *prev;
        while(ptr->next != NULL){
            prev = ptr;
            ptr = ptr->next;
        }
        prev->next = NULL;
        delete ptr;
    }
}
//delete after a given data
void deleteAfter(node* &head, int x){
    if(head == NULL){
        cout << "list is empty";
    }
    else if(head->next == NULL){
        delete head;
        head = NULL;
    }
    else{
        node *ptr = head, *after;
        while(ptr->data != x){
            ptr = ptr->next;
        }
        after = ptr->next;
        ptr->next = after->next;
        delete after;
    }
}
