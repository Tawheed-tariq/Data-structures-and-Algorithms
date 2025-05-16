class Solution {
    public:
        bool findTarget(TreeNode* root, int k) {
            return checkSum(root, root, k);
        }
        
        bool checkSum(TreeNode* node, TreeNode* root, int k) {
            if (!node) return false;
            
            if (search(root, k - node->val, node)) return true;
    
            return checkSum(node->left, root, k) || checkSum(node->right, root, k);
        }
        
        bool search(TreeNode* node, int target, TreeNode* ignore) {
            while (node) {
                if (node->val == target && node != ignore) return true;
                node = target < node->val ? node->left : node->right;
            }
            return false;
        }
    };
    