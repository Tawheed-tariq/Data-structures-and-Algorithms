#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node *next;
    node(int d){
        this -> data = d;
        this -> next = NULL;
    }
    ~node(){
        int val = this->data;
        if(this->next != NULL){
            delete next;
            next = NULL;
        }
        cout << "memory deleted for node of data " << val << endl;
    }
};
//insert node at a position
void insertNode(node* &tail, int x, int d){
    //assuming x is present is list
    if(tail == NULL){
        //empty list
        node *temp = new node(d);
        temp->next = temp;
        tail = temp;
    }
    else{
        node *temp = new node(d);
        node *curr = tail;
        while(curr->data != x){
            curr = curr->next;
        }
        //element found
        temp->next = curr->next;
        curr->next = temp;
    }
}

//traverse
void traverse(node* tail){
    if(tail == NULL){
        cout << "list empty" << endl;
        return;
    }
    node *ptr = tail;
    do{
        cout << tail ->data << " ";
        tail = tail ->next;
    }while(tail != ptr);
    cout << endl;
}


//deletion
void deleteNode(node* &tail, int x){
    //empty list
    if(tail == NULL){
        cout << "list is empty" << endl;
    }
    else{
        node *prev = tail, *curr = prev -> next;
        while(curr->data != x){
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr-> next;
        if(curr == prev){
            tail = NULL;
        }
        if(tail == curr){
            tail = prev;
        }
        curr->next = NULL;
        delete curr;
    }
}

int main(){
    node *tail = NULL;
    insertNode(tail,0,10);
    // insertNode(tail,10,5);
    // insertNode(tail,10,6);
    // insertNode(tail,5,1);
    // traverse(tail);
    deleteNode(tail,10);
    traverse(tail);
}