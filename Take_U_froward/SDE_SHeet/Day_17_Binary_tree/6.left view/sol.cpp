class Solution {
    public:
      void func(Node *root, int lvl, vector<int> &ans){
          if(root == NULL)
              return;
          if(lvl == ans.size()) //entered new level
              ans.push_back(root->data);
          func(root->left, lvl+1, ans);
          func(root->right, lvl+1, ans);
      }
      vector<int> leftView(Node *root) {
          vector<int> ans;
          if(root == NULL)
              return ans;
          func(root, 0, ans);
          return ans;
      }
  };