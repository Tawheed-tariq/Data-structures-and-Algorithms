class Solution {
    public:
        void solve(vector<vector<char>>& grid, int i, int j, int rows, int cols){
            if(i < 0 || i >= rows || j < 0 || j >= cols || grid[i][j] != '1') return;
            grid[i][j] = '0'; //mark as visited
            solve(grid, i-1, j, rows, cols);
            solve(grid, i+1, j, rows, cols);
            solve(grid, i, j-1, rows, cols);
            solve(grid, i, j+1, rows, cols);
        }
        int numIslands(vector<vector<char>>& grid) {
            if(grid.empty() || grid[0].empty()) return 0;
            int rows = grid.size(), cols = grid[0].size();
            int count = 0;
            for(int i = 0; i < rows; i++){
                for(int j = 0; j < cols; j++){
                    if(grid[i][j] == '1'){
                        count++;
                        solve(grid, i, j, rows, cols);
                    }
                }
            }
            return count;
        }
    };