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
 int ans;
class Prop{
    public:
    bool is_bst;
    int maxx;
    int minn;
    int max_sum;
    Prop(){
        is_bst = true;
        maxx = INT_MIN;
        minn = INT_MAX;
        max_sum = 0;
    }
};
class Solution {
public:
    Prop calcSum(TreeNode *root){
        if(!root) return Prop();

        Prop p_curr;
        Prop p_left = calcSum(root->left);
        Prop p_right = calcSum(root->right);

        if(p_left.is_bst && p_right.is_bst && root->val < p_right.minn && root->val > p_left.maxx){
            //curr is bst
            p_curr.is_bst = true;
            p_curr.max_sum = p_left.max_sum + p_right.max_sum + root->val;
            p_curr.maxx = max(p_right.maxx, root->val);
            p_curr.minn = min(root->val, p_left.minn);
        }else{
            //not bst
            p_curr.is_bst = false;
            p_curr.max_sum = max(p_left.max_sum, p_right.max_sum);
        }
        ans = max(ans, p_curr.max_sum);
        return p_curr;
    }
    int maxSumBST(TreeNode* root) {
        ans = 0;
        calcSum(root);
        return ans;

    }
};