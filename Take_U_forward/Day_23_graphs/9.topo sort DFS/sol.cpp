class Solution {
    public:
      // Function to return list containing vertices in Topological order.
      void dfs(int node, vector<bool> &vis, unordered_map<int, vector<int>> &mp, stack<int> &st){
          vis[node] = true;
          
          for(auto neighbor: mp[node]){
              if(!vis[neighbor]) dfs(neighbor, vis, mp, st);
          }
          st.push(node);
      }
      
      vector<int> topologicalSort(vector<vector<int>>& adj) {
          unordered_map<int, vector<int>> mp;
          vector<bool> vis(adj.size(), false);
          stack<int> st;
          for(int i = 0; i < adj.size(); i++){
              mp[i] = adj[i];
          }
          
          for(int i=0; i < adj.size(); i++){
              if(!vis[i]) dfs(i, vis, mp, st);
          }
          vector<int> ans;
          while(!st.empty()){
              ans.push_back(st.top());
              st.pop();
          }
          return ans;
      }
  };