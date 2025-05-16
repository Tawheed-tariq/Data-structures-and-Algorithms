class Solution {
    public:
        int solve(vector<vector<int>>& grid, int x, int y){
            if(x >= grid.size() || y >= grid[0].size()) return 1e9;
    
            if(x == grid.size()-1 && y == grid[0].size()-1) return grid[x][y];
    
            int down = solve(grid, x+1, y);
            int right = solve(grid, x, y+1);
    
            return grid[x][y] +min(right, down);
        }
        int minPathSum(vector<vector<int>>& grid) {
            return solve(grid, 0 ,0);
        }
    };