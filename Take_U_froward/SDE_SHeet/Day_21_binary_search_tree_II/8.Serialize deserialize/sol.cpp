/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 #include <sstream>
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string str = "";
        if(!root) return str;

        queue<TreeNode *> q;
        q.push(root);

        while(!q.empty()){
            TreeNode *front = q.front();
            q.pop();

            if(!front){
                str += "#,";
            }else{
                str += to_string(front->val) + ",";
                q.push(front->left);
                q.push(front->right);
            }
        }
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty()) return NULL;

        stringstream s(data);
        string str;

        getline(s, str, ',');
        TreeNode *root = new TreeNode(stoi(str));
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()){
            TreeNode *front = q.front();
            q.pop();

            getline(s, str, ',');
            if(str != "#"){
                TreeNode *left = new TreeNode(stoi(str));
                front->left = left;
                q.push(left);
            }

            getline(s, str, ',');
            if(str != "#"){
                TreeNode *right = new TreeNode(stoi(str));
                front->right = right;
                q.push(right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));