class Solution {
    public:
        int solve(vector<vector<int>>& grid, int x, int y, vector<vector<int>> &dp){
            if(x >= grid.size() || y >= grid[0].size()) return 1e9;
    
            if(x == grid.size()-1 && y == grid[0].size()-1) return grid[x][y];
            
            if(dp[x][y] != -1) return dp[x][y];
            int down = solve(grid, x+1, y, dp);
            int right = solve(grid, x, y+1, dp);
    
            return dp[x][y] = grid[x][y] +min(right, down);
        }
        int minPathSum(vector<vector<int>>& grid) {
            vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), -1));
            return solve(grid, 0 ,0, dp);
        }
    };