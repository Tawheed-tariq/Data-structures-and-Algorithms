class Solution {
    public:
      // Function to find sum of weights of edges of the Minimum Spanning Tree.
      int spanningTree(int V, vector<vector<int>> adj[]) {
          priority_queue<pair<int,int> , vector<pair<int, int>> , greater<pair<int, int>>> pq;
          vector<bool> vis(V, false);
          pq.push({0,0}); //{weight, node}
          int sum = 0;
          
          while(!pq.empty()){
              auto front = pq.top();
              pq.pop();
              
              int node = front.second;
              int wt = front.first;
              
              if(vis[node]) continue;
              sum += wt;
              vis[node] = true;
              
              for(auto neighbor: adj[node]){
                  int node_i = neighbor[0];
                  int wt_i = neighbor[1];
                  if(!vis[node_i]) pq.push({wt_i, node_i});
              }
          }
          return sum;
      }
  };