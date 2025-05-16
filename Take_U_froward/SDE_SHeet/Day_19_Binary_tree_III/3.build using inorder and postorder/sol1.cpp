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
        TreeNode *solve(vector<int> &inorder, int inStrt, int inEnd, vector<int> &postorder, int postStrt, map<int, int> nodeToIndex){
            if(postStrt < 0 || inStrt > inEnd) return NULL;
    
            int ele = postorder[postStrt];
            int inRoot = nodeToIndex[ele];
            int numsRight = inEnd - inRoot;
    
            TreeNode *root = new TreeNode(ele);
            root->right = solve(inorder, inRoot+1, inEnd, postorder, postStrt-1, nodeToIndex);
            root->left = solve(inorder, inStrt, inRoot-1, postorder, postStrt-numsRight-1, nodeToIndex);
            
            return root;
        }
        TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
            map<int, int> nodeToIndex;
            for(int i =0; i < inorder.size(); i++){
                nodeToIndex[inorder[i]] = i;
            }
            TreeNode *ans = solve(inorder, 0, inorder.size()-1, postorder, postorder.size() - 1, nodeToIndex);
            return ans;
        }
    };