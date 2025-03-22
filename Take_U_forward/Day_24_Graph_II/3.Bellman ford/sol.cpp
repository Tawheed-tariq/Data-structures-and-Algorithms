class Solution {
    public:
      /*  Function to implement Bellman Ford
       *   edges: vector of vectors which represents the graph
       *   src: source vertex
       *   V: number of vertices
       */
      vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
          int e = edges.size();
          vector<int> dist(V, 1e8);
          dist[src] = 0;
          
          for(int i = 0; i < V-1; i++){
              bool relaxed = 0;
              for(int j = 0; j< e; j++){
                  int node_i = edges[j][0], node_j = edges[j][1], w_ij = edges[j][2];
                  if(dist[node_i] != 1e8 && dist[node_i] + w_ij < dist[node_j])
                      dist[node_j] = dist[node_i] + w_ij, relaxed = 1;
              }
              if(!relaxed) break;
          }
          
          for(int j = 0; j< e; j++){
              int node_i = edges[j][0], node_j = edges[j][1], w_ij = edges[j][2];
              if(dist[node_i] + w_ij < dist[node_j] && dist[node_i] != 1e8){
                  return {-1};
              }
          }
          return dist;
      }
  };