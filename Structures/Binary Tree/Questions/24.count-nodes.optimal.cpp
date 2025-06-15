class Solution {
public:
    int countNodes(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        int lh = findLeftHeight(root);
        int rh = findRightHeight(root);

        if (lh == rh)
            return (1 << lh) - 1;  // 2^lh - 1 nodes in perfect tree

        return 1 + countNodes(root->left) + countNodes(root->right);
    }

    int findLeftHeight(TreeNode* node) {
        int hght = 0;
        while (node) {
            hght++;
            node = node->left;
        }
        return hght;
    }

    int findRightHeight(TreeNode* node) {
        int hght = 0;
        while (node) {
            hght++;
            node = node->right;
        }
        return hght;
    }
};