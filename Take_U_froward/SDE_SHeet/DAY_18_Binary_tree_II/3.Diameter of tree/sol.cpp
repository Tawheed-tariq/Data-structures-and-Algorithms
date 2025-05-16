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
    
        // diameter of left
        // diameter of right
        // height(right) + height(left) + 1
        // max of the above 3 will be the answer
        pair<int, int> dia(TreeNode *root){
            pair<int, int> ans;
            if(root == NULL) return {0,0};
    
            pair<int, int> left = dia(root->left);
            pair<int, int> right = dia(root->right);
            int op1 = left.first, op2 = right.first;
            int op3 = left.second + right.second;
            ans.first = max(op1, max(op2, op3)); //max of all the three
    
            ans.second = max(left.second , right.second) + 1; // heigth of subtree
            return ans;
        }
        int diameterOfBinaryTree(TreeNode* root) {
            return dia(root).first;
        }
    };