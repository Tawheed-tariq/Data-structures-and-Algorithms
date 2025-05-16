class Solution {
    public:
      vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
          vector<int> dist(adj.size(), INT_MAX);
          set<pair<int, int>> st;
          
          dist[src] = 0;
          st.insert({0, src});
          
          while(!st.empty()){
              pair<int, int> top = *(st.begin());
              int node_dist = top.first, node = top.second;
              st.erase(st.begin());
              for(auto it: adj[node]){
                  if(node_dist + it.second < dist[it.first]){
                      auto record = st.find({dist[it.first], it.first});
                      
                      if(record != st.end()){
                          st.erase(record);
                      }
                      dist[it.first] = node_dist + it.second;
                      st.insert({dist[it.first], it.first});
                  }
              }
          }
          return dist;
      }
  };