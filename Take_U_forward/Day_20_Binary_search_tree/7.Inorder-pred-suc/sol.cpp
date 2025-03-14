class Solution
{
    public:
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
    {
        Node *temp1 = root, *temp2 = root;
        //inorder predecossor : max of left subtree
        while(temp1){
            if(temp1->key >= key)
                temp1 = temp1->left;
            else{
                pre= temp1;
                temp1 = temp1->right;
            }
        }
        //inorder successor: min of right subtree
        while(temp2){
            if(temp2->key <= key) 
                temp2 = temp2->right;
            else{
                suc = temp2;
                temp2 = temp2->left;
            }
        }
    }
};