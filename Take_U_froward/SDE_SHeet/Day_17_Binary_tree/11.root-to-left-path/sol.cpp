class Solution {
    public:
    
      void solve(Node *root, vector<int> &path, vector<vector<int>> &ans){
          if(root->right == NULL && root->left == NULL){
              path.push_back(root->data);
              ans.push_back(path);
              path.pop_back();
              return;
          }
          path.push_back(root->data);
          if(root->left) solve(root->left, path, ans);
          
          if(root->right) solve(root->right, path, ans);
          path.pop_back();
      }
      vector<vector<int>> Paths(Node* root) {
          vector<int> path;
          vector<vector<int>> ans;
          solve(root, path, ans);
          return ans;
      }
  };