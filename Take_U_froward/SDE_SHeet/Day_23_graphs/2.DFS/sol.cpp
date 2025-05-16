class Solution {
    public:
      void solve(int node,vector<vector<int>>& adj, unordered_map<int, bool> &vis, vector<int> &ans){
          ans.push_back(node);
          vis[node] = true;
          
          for(auto i: adj[node]){
              if(!vis[i]) solve(i, adj, vis, ans);
          }
          
      }
      // Function to return a list containing the DFS traversal of the graph.
      vector<int> dfsOfGraph(vector<vector<int>>& adj) {
          vector<int> ans;
          unordered_map<int, bool> vis;
          solve(0, adj, vis, ans);
          return ans;
      }
  };