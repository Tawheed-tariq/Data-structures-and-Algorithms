#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node *left;
    node *right;
    node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};
// creation
node *buildTree(node *root){
    int data;
    cout << "enter data: " << endl;
    cin >> data;
    root = new node(data);

    if(data == -1){
        return NULL;
    }
    cout << "enter data for left of " << data << endl;
    root->left = buildTree(root->left);
    cout << "enter data for right of " << data << endl;
    root->right = buildTree(root->right);
    return root;
}
//level order traversal
void levelOrderTraversal(node *root){
    queue<node *> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node *temp = q.front();
        q.pop();

        if(temp == NULL){
            cout << endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }else{
            cout << temp->data << " ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}

//reverse level order traversal
void reverseLevelOrder(node *root){
    stack<node *> s;
    queue<node *> q;
    q.push(root);
    while(!q.empty()){
        node *temp = q.front();
        q.pop();
        s.push(temp);
        if(temp->right){
            q.push(temp->right);
        }
        if(temp->left){
            q.push(temp->left);
        }
    }
    while(!s.empty()){
        node *temp = s.top();
        cout << temp->data << " ";
        s.pop();
    }

}


//inorder traversal LNR(left node right)
void inOrder(node *root){
    if(root == NULL){
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

//pre order traversal NLR(node left right)
void preOrder(node *root){
    if(root == NULL){
        return;
    }
    cout << root->data << " "; 
    preOrder(root->left);
    preOrder(root->right);
}

//post order traversal LRN(left right node)
void postOrder(node *root){
    if(root == NULL)
        return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

//build from level order traversal
node *buildFromLevelOrder(node *root){
    queue<node *> q;
    int data;
    cout << "enter data :" << endl;
    cin >> data;
    root = new node(data);
    q.push(root);

    while(!q.empty()){
        node *temp = q.front();
        q.pop();

        int leftData , rightData;
        cout << "enter data for left of " << temp->data << endl;
        cin >> leftData;
        if(leftData != -1)
        {temp->left = new node(leftData);
        q.push(temp->left);}

        cout << "enter data for rigth of " << temp->data << endl;
        cin >> rightData;
        if(rightData != -1)
       { temp->right = new node(rightData);
        q.push(temp->right);}
    }
    return root;
}

//1 3 4 -1 -1 5 -1 -1 2 6 -1 -1 -1 
int main(){
    node *root = NULL;
    root = buildFromLevelOrder(root);//1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
    reverseLevelOrder(root);
    // inOrder(root);
}