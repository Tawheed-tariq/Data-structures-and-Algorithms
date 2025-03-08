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
        int widthOfBinaryTree(TreeNode* root) {
            queue<pair<TreeNode *, long long>> q;
            long long ans = 0;
            
            q.push({root, 0});
            while(!q.empty()){
                long long size = q.size();
                long long mini = q.front().second;
                long long first, last;
    
                for(int i = 0; i < size; i++){
                    long long curr_id = q.front().second - mini;
                    TreeNode *curr_node = q.front().first;
    
                    q.pop();
    
                    if(i == 0) first = curr_id;
                    if(i == size-1) last = curr_id;
    
                    if(curr_node->left) q.push({curr_node->left, 2*curr_id +1});
    
                    if(curr_node->right) q.push({curr_node->right, 2*curr_id +2});
    
                }
                ans = max(ans, last-first+1);
            }
            return ans;
        }
    };