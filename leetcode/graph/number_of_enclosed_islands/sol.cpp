class Solution {
public:
    vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    void dfs(vector<vector<int>>& grid, int m, int n, int i, int j, bool &island){
        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != 0) return;

        if((i -1 < 0 || i+1 >= m || j-1 < 0 || j+1 >= n) && grid[i][j] == 0){
            island = false;
            return;
        }

        grid[i][j] = 1;
        for(auto &dir : dirs){
            dfs(grid, m, n, i + dir[0], j + dir[1], island);
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        int count = 0;
        int m = grid.size(), n = grid[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0){
                    bool island = true;
                    dfs(grid, m, n, i, j, island);
                    if(island){
                        count++;
                    }
                }
            }
        }
        return count;
    }
};