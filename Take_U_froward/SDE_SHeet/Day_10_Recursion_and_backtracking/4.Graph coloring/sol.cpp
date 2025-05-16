class Solution {
    public:
      bool isSafe(int node, int v, vector<int> &color, vector<vector<int>> &edges, int m, int col){
          for(int i:edges[node]){
              if(color[i] == col)
                  return false;
          }
          return true;
      }
      bool solve(int node, vector<int> &color, int m, int v, vector<vector<int>> &edges){
          if(node == v){
              return true;
          }
          
          //check for every color in this node
          for(int i = 1; i <= m; i++){
              if(isSafe(node, v, color, edges, m, i)){
                  color[node] = i;
                  if(solve(node+1, color, m, v, edges)) return true;
                  color[node] = 0;
              }
          }
          return false;
      }
      bool graphColoring(int v, vector<pair<int, int>>& edges, int m) {
          vector<int> color(v+1, 0);
          vector<vector<int>> adj(v);
          for(auto it:edges){
              adj[it.first].push_back(it.second);
              adj[it.second].push_back(it.first);
          }
          return solve(0, color, m, v, adj);
      }
  };