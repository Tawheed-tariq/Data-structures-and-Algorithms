#include<iostream>
using namespace std;
class queue{
    int *arr;
    int size;
    int front;
    int rear;
    public:
    queue(int s){
        size = s;
        arr =new int[s];
        front = -1;
        rear = -1;
    }
    void enqueue(int data){
        if(rear == size-1){
            cout << "queue overflow" << endl;
        }else{
            arr[++rear] = data;
            if(front == -1){
                front++;
            }
        }
    }
    void dequeue(){
        if(front == -1){
            cout << "stack underflow" << endl;
        }else{
            cout << "deleted "<< arr[front] << endl;
            front++;
        }
    }
    int getFront(){
        if(front == -1){
            return -1;
        }
        return arr[front];
    }
    bool isEmpty(){
        if(front == -1){
            return true;
        }
        return false;
    }
};


int main(){
    queue q(14);
    q.enqueue(12);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(7);
    cout << q.getFront() << endl;
    q.dequeue();
    cout << q.getFront() << endl;
    cout << q.isEmpty() << endl;
}