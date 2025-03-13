class Solution {
    public:
      // Function to return Breadth First Traversal of given graph.
      vector<int> bfsOfGraph(vector<vector<int>> &adj) {
          vector<int> ans;
          queue<int> q;
          unordered_map<int, bool> vis;
          
          q.push(0);
          vis[0] = true;
          
          while(!q.empty()){
              int node = q.front();
              q.pop();
              ans.push_back(node);
              
              for(auto i: adj[node]){
                  if(!vis[i]){
                      q.push(i);
                      vis[i] = true;
                  }
              }
          }
          return ans;
      }
  };