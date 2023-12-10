#include<iostream>
using namespace std;
class stack{
    int *arr;
    int top;
    int size;
    public:
    stack(int n){
        size = n;
        arr = new int[n];
        top = -1;
    }
    void push(int data){
        if(top == size-1){
            cout << "stack overflow" << endl;
        }else{
            arr[++top] = data;
        }
    }
    void pop(){
        if(top == -1){
            cout << "stack underflow" << endl;
        }else{
            cout << "deleted " << arr[top] << endl;
            top--;
        }
    }
    void peek(){
        if(top == -1){
            cout << "stack is empty" << endl;
        }else{
            cout << "top element is :" << arr[top] << endl;
        }
    }
    bool isEmpty(){
        if(top == -1){
            return true;
        }else{
            return false;
        }
    }
};

int main(){
    stack s(5);
    s.push(12);
    s.push(13);
    s.push(15);
    s.peek();
    s.pop();
    s.peek();
}