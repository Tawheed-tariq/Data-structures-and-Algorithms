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
        int solve(TreeNode * root, int height){
            if(root == NULL) return height;
    
            int leftHeight = solve(root->left, height+1);
            int rightHeight = solve(root->right, height+1);
    
            return max(leftHeight, rightHeight);
        }
        int maxDepth(TreeNode* root) {
            int height = solve(root , 0);
            return height;
        }
    };