/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
 class BSTIterator {
    public:
        vector<int> inorder;
        int i;
        void traverse(TreeNode *root, vector<int> &ans){
            if(!root) return;
            traverse(root->left, ans);
            ans.push_back(root->val);
            traverse(root->right, ans);
        }
        BSTIterator(TreeNode* root) {
            traverse(root, inorder);
            i = 0;
        }
        
        int next() {
            return inorder[i++];
        }
        
        bool hasNext() {
            return i < inorder.size();
        }
    };
    
    /**
     * Your BSTIterator object will be instantiated and called as such:
     * BSTIterator* obj = new BSTIterator(root);
     * int param_1 = obj->next();
     * bool param_2 = obj->hasNext();
     */