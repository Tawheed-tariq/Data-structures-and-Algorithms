class Solution {
    public:
      // Function to return list containing vertices in Topological order.
      vector<int> topologicalSort(vector<vector<int>>& adj) {
          vector<int> inDegree(adj.size(), 0);
          queue<int> q;
          vector<int> ans;
          for(int i =0; i < adj.size(); i++){
              for(auto x: adj[i]){
                  inDegree[x]++;
              }
          }
          
          for(int i = 0; i < adj.size(); i++){
              if(inDegree[i] == 0) q.push(i);
          }
          
          while(!q.empty()){
              int front = q.front();
              q.pop();
              ans.push_back(front);
              for(auto neighbor: adj[front]){
                  inDegree[neighbor]--;
                  if(inDegree[neighbor] == 0) q.push(neighbor);
              }
          }
          return ans;
      }
  };
  