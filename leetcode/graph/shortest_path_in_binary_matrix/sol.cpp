class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int n = grid.size();
        if(grid[0][0] != 0) return -1;
        q.push({0, 0});
        grid[0][0] = 1;
        int steps = 1;
        vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {1, 1}, {-1, 1}, {1, -1}};
        while(!q.empty()){
            int size = q.size();
            while(size--){
                auto [row, col] = q.front(); q.pop();
                if(row == n-1 && col == n-1) return steps;
                for(auto dir: dirs){
                    int r = row + dir[0];
                    int c = col + dir[1];

                    if(r >=0 && r < n && c >= 0 && c < n && grid[r][c] != 1){
                        q.push({r, c});
                        grid[r][c] = 1;
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};