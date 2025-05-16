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
        vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
            bool right_to_left = false;
            vector<vector<int>> ans;
            if(!root) return ans;
            vector<int> res;
            queue<TreeNode *> q;
            q.push(root);
            q.push(NULL);
    
            while(!q.empty()){
                TreeNode *node = q.front();
                q.pop();
    
                if(node == NULL){
                    if(right_to_left){
                        reverse(res.begin(), res.end());
                        ans.push_back(res);
                    }else{
                        ans.push_back(res);
                    }
                    res.erase(res.begin(), res.end());
                    right_to_left = !right_to_left;
                    if(!q.empty())
                        q.push(NULL);
                }else{
                    res.push_back(node->val);
                    if(node->left) q.push(node->left);
                    if(node->right) q.push(node->right);
                }
            }
            return ans;
        }
    };