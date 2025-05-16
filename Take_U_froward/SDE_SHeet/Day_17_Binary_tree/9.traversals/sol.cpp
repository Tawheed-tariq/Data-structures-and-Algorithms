/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/
void inOrder(TreeNode *root, vector<int> &In){
    if(root == NULL){
        return;
    }
    inOrder(root->left, In);
    In.push_back(root->data);
    inOrder(root->right, In);
}
void preOrder(TreeNode *root, vector<int> &pre){
    if(root == NULL){
        return;
    }
    pre.push_back(root->data); 
    preOrder(root->left, pre);
    preOrder(root->right, pre);
}
void postOrder(TreeNode *root, vector<int> &post){
    if(root == NULL)
        return;
    postOrder(root->left, post);
    postOrder(root->right, post);
    post.push_back(root->data);
}

vector<vector<int>> getTreeTraversal(TreeNode *root){
    vector<int> In, pre, post;
    vector<vector<int> > ans;
    inOrder(root, In);
    preOrder(root, pre);
    postOrder(root,post);
    ans.push_back(In);
    ans.push_back(pre);
    ans.push_back(post);
    return ans;
}