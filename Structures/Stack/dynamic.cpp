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
class stack{
    node *top;
    public:
    stack(){
        top = NULL;
    }
    //insert element
    void push(int info){
        node *n = new node(info);
        if(n == NULL){
            cout << "Stack overflow" << endl;
        }
        n->next = top;
        top = n;
    }
    //delete element
    void pop(){
        if(top == NULL){
            cout << "stack is empty" << endl;
        }
        cout << "deleted " << top->data << endl;
        node *temp = top;
        top = top ->next;
        delete temp;
    }
    void peek(){
        if(top == NULL){
            cout << "stack is empty" << endl;
        }else{
            cout << top->data << endl;
        }
    }
};

int main(){
    stack s;
    s.push(12);
    s.push(24);
    s.push(18);
    s.peek();
    s.pop();
    s.peek();
}