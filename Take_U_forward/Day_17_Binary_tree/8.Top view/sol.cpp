class Solution {
    public:
      // Function to return a list of nodes visible from the top view
      // from left to right in Binary Tree.
      vector<int> topView(Node *root) {
          vector<int> ans;
          if(root == NULL)
              return ans;
          queue<pair<Node *, int>> q;
          map<int, int> mp;
          
          q.push({root, 0});
          
          while(!q.empty()){
              pair<Node *, int> topNode = q.front();
              q.pop();
              Node *node = topNode.first;
              int hd = topNode.second;
              
              if(mp.find(hd) == mp.end())
                  mp[hd] = node->data;
              if(node->left)
                  q.push({node->left, hd-1});
              if(node->right)
                  q.push({node->right, hd+1});
          }
          
          
          for(auto x: mp){
              ans.push_back(x.second);
          }
          return ans;
      }
  };