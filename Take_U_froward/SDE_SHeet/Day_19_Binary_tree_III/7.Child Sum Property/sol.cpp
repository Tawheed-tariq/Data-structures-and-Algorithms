class Solution{
    public:
    //Function to check whether all nodes of a tree have the value 
    //equal to the sum of their child nodes.
    int isSumProperty(Node *root)
    {
     if(!root) return 1;
     int left = 0, right = 0;
     if(root->left) left = root->left->data;
     if(root->right) right = root->right->data;
     
     int sum1 = isSumProperty(root->left);
     int sum2 = isSumProperty(root->right);
     //for leaf node we dont have to check values
     return left == 0 && right == 0? sum1 && sum2 :sum1 && sum2 && root->data == left+right;
    }
};