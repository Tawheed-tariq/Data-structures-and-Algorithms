class Solution {
    public:
        int find(vector<vector<int>> &path, int m, int n, vector<vector<int>>& grid){
            if(m == 0 && n == 0 && grid[m][n] == 0)
                return 1;
            if( m < 0 || n < 0)
                return 0;
            if(grid[m][n] == 1)
                return path[m][n] = 0;
            
            if(path[m][n] != -1)
                return path[m][n];
    
            path[m][n] = find(path, m-1, n, grid) + find(path, m, n-1, grid);
    
            return path[m][n];
        }
        int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
            int m = obstacleGrid.size();
            int n = obstacleGrid[0].size();
            if(m ==1 && n == 1 && obstacleGrid[m-1][n-1] == 1)
                return 0;
            vector<vector<int>> path(m, vector<int>(n, -1));
            return find(path, m-1, n-1, obstacleGrid);
        }
    };