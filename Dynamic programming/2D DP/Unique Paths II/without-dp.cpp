class Solution {
    public:
        void solve(int i, int j, int &count, vector<vector<int>>& grid, int rows, int cols){
            if(i == rows-1 && j == cols-1)
                count++;
            if(i >= rows || j >= cols || grid[i][j] == 1)
                return;
    
            solve(i+1, j, count, grid, rows, cols);
            solve(i , j+1, count, grid, rows, cols);
        }
        int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
            int count  = 0;
            int rows = obstacleGrid.size();
            int cols = obstacleGrid[0].size();
            solve(0, 0, count, obstacleGrid, rows, cols);
            return count;
        }
    };