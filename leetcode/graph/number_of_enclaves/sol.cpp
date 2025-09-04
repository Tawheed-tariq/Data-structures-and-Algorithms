class Solution {
public:
    void dfs(vector<vector<int>>& grid,int m , int n, int i, int j, bool &joined, int &count){
        if(i < 0 || j < 0 || i >= m || j >= n || grid[i][j] != 1) return;
        if((i-1 < 0 || i+1 >= m || j-1 < 0 || j+1 >= n) && grid[i][j] == 1){
            joined = true;
            count++;
            return;
        }
        count++;
        grid[i][j] = 0;
        dfs(grid, m, n, i+1, j, joined, count);
        dfs(grid, m , n, i-1, j, joined, count);
        dfs(grid, m, n, i, j-1, joined, count);
        dfs(grid, m, n, i, j+1, joined, count);
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int count = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    bool joined = false;
                    int tmp = 0;
                    dfs(grid,m , n, i , j, joined, tmp);

                    if(!joined){
                        count += tmp;
                    }
                }
            }
        }
        return count;
    }
};