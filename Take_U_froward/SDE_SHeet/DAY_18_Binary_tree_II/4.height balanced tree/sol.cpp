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
 class Solution {
    public:
        int solve(TreeNode * root, int height, bool &ans){
            if(root == NULL) return height;
    
            int leftHeight = solve(root->left, height+1, ans);
            int rightHeight = solve(root->right, height+1, ans);
            if(abs(leftHeight - rightHeight) > 1) ans = false;
            return max(leftHeight, rightHeight);
        }
        bool isBalanced(TreeNode* root) {
            bool ans = true;
            solve(root, 0, ans);
            return ans;
        }
    };