class Solution {
    public:
      void shortestDistance(vector<vector<int>>& mat) {
          int V = mat.size();
          for(int k = 0; k < V; k++){
              for(int i = 0; i < V; i++){
                  for(int j = 0; j < V; j++){
                      if(mat[i][k] == -1 || mat[k][j] == -1) continue;
                      if(mat[i][j] == -1) mat[i][j] = INT_MAX;
                      mat[i][j] = min(mat[i][j], mat[i][k]+mat[k][j]);
                  }
              }
          }
      }
  };