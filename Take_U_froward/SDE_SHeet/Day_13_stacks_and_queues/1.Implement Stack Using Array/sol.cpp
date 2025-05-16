/*
class MyStack
{
private:
    int arr[1000];
    int top;
public:
    MyStack(){top=-1;}
    int pop();
    void push(int);
};
*/

void MyStack ::push(int x) {
    if(top == -1){
        top = 0;
    }else{
        top++;
    }
    arr[top] = x;
}

// Function to remove an item from top of the stack.
int MyStack ::pop() {
    return top == -1 ? top : arr[top--];
}