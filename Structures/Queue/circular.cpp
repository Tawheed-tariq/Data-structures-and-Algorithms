#include<iostream>
using namespace std;
class queue{
    int *arr;
    int size;
    int front;
    int rear;
    bool isFull(){
        if((front == 0 && rear == size-1) || (rear == (front-1)%(size-1)))
            return true;
        return false;
    }
    bool isEmpty(){
        if(front == -1)
            return true;
        return false;
    }
    public:
    queue(int s){
        size = s;
        arr =new int[s];
        front = -1;
        rear = -1;
    }
    void enqueue(int info){
        if(isFull()){
            cout << "queue overflow" << endl;
            return;
        }
        if(rear == size-1){
            rear = 0;
        }else if(front == -1){
            front = rear= 0;
        }else{
            rear++;
        }
        arr[rear] = info;
    }
    void dequeue(){
        if(isEmpty()){
            cout << "queue underflow" << endl;
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
    int getFront(){
        if(front == -1){
            return -1;
        }
        return arr[front];
    }
};

int main(){
    queue q(6);
    q.enqueue(5);
    q.enqueue(6);
    q.enqueue(8);
    q.enqueue(56);
    cout << q.getFront() << endl;
    q.dequeue();
    q.dequeue();
    cout << q.getFront() << endl;
}