#include<iostream>
#include<bits/stdc++.h>
using namespace std;


class node{
    public:
    int data;
    node *left;
    node *right;
    node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

//insert node to BST
node *insertIntoBST(node* &root, int ele){
    if(root == NULL){
        root = new node(ele);
        return root;
    }
    if(ele > root->data){
        insertIntoBST(root->right, ele);
    }else{
        insertIntoBST(root->left, ele);
    }
    return root;
}
//take inputs
void takeInput(node* &root){
    int ele;
    cout << "enter elements : ";
    cin>> ele;
    while(ele != -1){
        insertIntoBST(root, ele);
        cin >> ele;
    }
}
//level order traveral
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
//search an element 
bool search(node *root, int val){
    if(root == NULL){
        return false;
    }
    if(root->data == val){
        return true;
    }else if(root->data > val){
        return search(root->left , val);
    }else{
        return search(root->right, val);
    }
}
//min value
node *minValue(node *root){
    node *temp = root;
    while(root->left != NULL){
        temp = temp->left;
    }
    return temp;
}
//max value
node *maxValue(node *root){
    node *temp = root;
    while(temp->right != NULL){
        temp = temp->right;
    }
    return temp;
}
//delete node
node *deleteNode(node *root, int ele){
    if(root == NULL){
        return NULL;
    }
    if(root->data == ele){
        if(root->left == NULL &&  root->right == NULL){
            delete root;
            return NULL;
        }
        if(root->left != NULL && root->right == NULL){
            node *temp = root->left;
            delete root;
            return temp;
        }
        if(root->right != NULL && root->left == NULL){
            node *temp = root->right;
            delete root;
            return temp;
        }
    }else if(root->data > ele){
        root = deleteNode(root->left , ele);
        return root;
    }else{
        root = deleteNode(root->right, ele);
        return root;
    }
}
int main(){
    node *root = NULL;
    takeInput(root);
    levelOrderTraversal(root);
}