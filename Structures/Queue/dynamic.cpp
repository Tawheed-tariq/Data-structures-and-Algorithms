#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node *next;
    node(int d){
        data = d;
        next = NULL;
    }
};
class queue{
    node *front , *rear;
    public:
    queue(){
        front = NULL;
        rear = NULL;
    }
    void enqueue(int data){
        node *n = new node(data);
        if(rear == NULL){
            rear = n;
            front = n;
        }else{
            rear->next = n;
            rear = n;
        }
    }
    void dequeue(){
        if(front == NULL){
            cout << "queue overflow" << endl;
        }else{
            node *temp = front;
            front = front->next;
            cout << "deleted " << temp->data << endl;
            delete temp;
        }
    }
    int getFront(){
        if(front == NULL){
            return -1;
        }
        return front->data;
    }
    bool isEmpty(){
        if(front == NULL){
            return true;
        }
        return false;
    }
};

int main(){
    queue q;
    cout << q.isEmpty() << endl;
    q.enqueue(12);
    q.enqueue(13);
    q.enqueue(34);
    cout << q.getFront() << endl;
    q.dequeue();
    cout << q.getFront() << endl;
    cout << q.isEmpty() << endl;
}