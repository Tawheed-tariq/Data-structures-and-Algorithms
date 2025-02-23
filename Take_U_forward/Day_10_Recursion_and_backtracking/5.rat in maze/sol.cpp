class Solution {
    public:
      bool isSafe(int row, int col, vector<vector<int>> &mat, vector<vector<bool>> &visited, int rows, int cols){
          if((row < rows && row >= 0) && (col < cols && col >= 0) && visited[row][col] != true && mat[row][col] == 1)
              return true;
          return false;
      }
      void solve(int row, int col, vector<string> &ans, vector<vector<bool>> &visited, vector<vector<int>> &mat, string path, int rows, int cols){
          if(row == rows-1 && col == cols-1){
              ans.push_back(path);
              return;
          }
          
          visited[row][col] = true;
          
          //go down
          if(isSafe(row+1, col, mat, visited, rows, cols))
              solve(row+1, col, ans, visited, mat, path+'D', rows, cols);
          //go left
          if(isSafe(row, col-1, mat, visited, rows, cols))
              solve(row, col-1, ans, visited, mat, path+'L', rows, cols);
          //go right
          if(isSafe(row, col+1, mat, visited, rows, cols))
              solve(row, col+1, ans, visited, mat, path+'R', rows, cols);
          //go up
          if(isSafe(row-1, col, mat, visited, rows, cols))
              solve(row-1, col, ans, visited, mat, path+'U', rows, cols);
              
          visited[row][col] = false;
      }
      vector<string> findPath(vector<vector<int>> &mat) {
          int rows = mat.size(), cols = mat[0].size();
          vector<vector<bool>> visited(rows, vector<bool>(cols, false));
          vector<string> ans;
          string path;
          solve(0,0, ans, visited, mat, path, rows, cols);
          return ans;
      }
  };