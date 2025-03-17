Node *prev = NULL, Node *head = NULL;
void convertToDLl(Node *root){
    if(root == NULL) return ;
    
    convertToDll(root->left);

    if(prev == NULL) head = root;
    else{
        root->left = prev;
        prev->right = root;
    }
    convertToDll(root->right);
}