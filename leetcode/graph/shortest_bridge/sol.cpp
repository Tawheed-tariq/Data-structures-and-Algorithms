class Solution {
public:
    queue<pair<int, int>> q;
    vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

    void dfs(int r, int c, int n, vector<vector<int>>& grid, vector<vector<bool>>& visited){
        if(r < 0 || c < 0 || r >= n || c >= n || grid[r][c] == 0 || visited[r][c]) return;

        visited[r][c] = true;
        q.push({r, c});

        for(auto &dir: dirs)
            dfs(r+dir[0], c+dir[1], n, grid, visited);
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<bool>> visited(n, vector<bool>(n , false));
        bool found = false;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    dfs(i, j, n, grid, visited);
                    found = true;
                    break;
                }
            }
            if(found) break;
        }


        int steps = 0;
        while(!q.empty()){
            int size = q.size();

            while(size--){
                auto curr = q.front(); q.pop();

                for(auto &dir : dirs){
                    int i = curr.first + dir[0];
                    int j = curr.second + dir[1];

                    if(i >= 0 && j >= 0 && i < n && j < n && !visited[i][j]){
                        if(grid[i][j] ==1) return steps;

                        q.push({i, j});
                        visited[i][j] = true;
                    }
                }
            }
            steps++;
        }
        return -1;

    }
};