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
        int solve(TreeNode *root, int &res){
            if(root == NULL) return 0;
    
            int left = solve(root->left, res);
            int leftMax = max(left, 0); //we dont want negative values
            int right = solve(root->right, res);
            int rightMax = max(right, 0);
    
            res = max(res, rightMax+leftMax+root->val);
            return max(rightMax+root->val, leftMax+root->val);
        }
        int maxPathSum(TreeNode* root) {
            int res = INT_MIN;
            solve(root, res);
            return res;
        }
    };