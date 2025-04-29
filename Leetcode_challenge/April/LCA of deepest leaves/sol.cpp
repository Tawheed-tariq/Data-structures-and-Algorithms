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
        pair<int, TreeNode*> helper(TreeNode *node){
            if(!node) return {0, NULL}; //height is 0 and leave node
    
            auto left = helper(node->left); //check height and lca of left subtree
            auto right = helper(node->right); //check height and lca for right subtree
    
            if(left.first == right.first) return {left.first+1, node}; //if height is same for both curr node is lca
            // else return for the one subtree with greater height
            else if(left.first > right.first){
                return {left.first+1, left.second};
            }else{
                return {right.first+1, right.second};
            }
        }
        TreeNode* lcaDeepestLeaves(TreeNode* root) {
            return helper(root).second;
        }
    };