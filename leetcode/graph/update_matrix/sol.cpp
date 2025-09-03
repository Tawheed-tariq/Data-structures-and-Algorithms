class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> dist(m , vector<int>(n));
        vector<vector<bool>> vis(m, vector<bool>(n, false));

        for(int i = 0; i < m ; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j] == 0){
                    q.push({i, j});
                    vis[i][j] = true;
                    dist[i][j] = 0;
                }else{
                    dist[i][j] = -1;
                }
            }
        }

        vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while(!q.empty()){
            auto [row, col] = q.front(); q.pop();

            for(auto [dr, dc]: dirs){
                int r = row+dr;
                int c = col + dc;

                if(r >= 0 && r < m && c >= 0 && c < n && !vis[r][c]){
                    q.push({r, c});
                    dist[r][c] = dist[row][col] + 1;
                    vis[r][c] = true;
                }
            }
        }

        return dist;
    }
};