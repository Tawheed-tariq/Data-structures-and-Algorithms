#include<iostream>
using namespace std;
class queue{
    int *arr;
    int front;
    int rear;
    int size;
    bool isFull(){
        if((front == 0 && rear == size-1) || (rear = (front -1)%(size-1)))
            return true;
        return false;
    }
    bool isEmpty(){
        if(front == -1){
            return true;
        }
        return false;
    }
    public:
    queue(int s){
        size = s;
        arr = new int[s];
        front = rear = -1;
    }
    void push_front(int info){
        if(isFull()){
            cout << "queue overflow" << endl;
            return;
        }
        if(front == -1){
            front = rear = 0;
        }else if(front == 0){
            front = size-1;
        }else{
            front--;
        }
        arr[front] = info;
    }
    void push_back(int info){
        if(isFull()){
            cout << "queue overflow" << endl;
            return;
        }
        if(rear == size -1){
            rear = 0;
        }else if(rear == -1){
            front = rear = 0;
        }else{
            rear++;
        }
        arr[rear] = info;
    }
    void pop_front(){
        if(isEmpty()){
            cout << "queue undeflow" << endl;
            return;
        }
        cout << "deleted " << arr[front] << endl;
        if(front == size-1){
            front = 0;
        }else if(front == rear){
            front = rear = -1;
        }else{
            front++;
        }
    }
    void pop_back(){
        if(isEmpty()){
            cout << "queue undeflow" << endl;
            return;
        }
        cout << "deleted " << arr[rear] << endl;
        if(rear == 0){
            rear = size -1;
        }else if(rear == front){
            front = rear = -1;
        }else{
            rear--;
        }
    }
};