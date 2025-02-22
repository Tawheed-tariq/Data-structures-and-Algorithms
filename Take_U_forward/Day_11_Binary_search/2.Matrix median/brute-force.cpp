class Solution {
    public:
      int median(vector<vector<int>> &mat) {
          vector<int> sorted;
          int m = mat.size();
          int n = mat[0].size();
          for(int i = 0; i < n*m; i++){
              sorted.push_back(mat[i/n][i%n]);
          }
          sort(sorted.begin(), sorted.end());
          return sorted[m*n/2];
          
      }
  };