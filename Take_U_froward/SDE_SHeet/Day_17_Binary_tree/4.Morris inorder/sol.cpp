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
        TreeNode *predecessor(TreeNode *root){
            TreeNode *curr = root->left;
            while(curr->right && curr->right != root)
                curr = curr->right;
            return curr;
        }
        vector<int> inorderTraversal(TreeNode* root) {
            vector<int> ans;
            TreeNode *curr = root;
    
            while(curr != NULL){
                if(curr->left == NULL){
                    ans.push_back(curr->val);
                    curr = curr->right;
                }else{
                    TreeNode *pred = predecessor(curr);
                    if(pred->right == NULL){
                        pred->right = curr;
                        curr = curr->left;
                    }else{
                        pred->right = NULL;
                        ans.push_back(curr->val);
                        curr = curr->right;
                    }
                }
            }
            return ans;
        }
    };