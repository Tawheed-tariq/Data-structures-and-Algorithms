class Solution {
    public:
        int orangesRotting(vector<vector<int>>& grid) {
            queue<pair<int, int>> q;
            int fresh = 0, time= 0;
            int rows = grid.size(), cols = grid[0].size();
    
            for(int i = 0; i < rows*cols; i++){
                if(grid[i/cols][i%cols] == 1)
                    fresh++;
                if(grid[i/cols][i%cols] == 2)
                    q.push({i/cols, i%cols});
            }
    
    
            int dx[4] = {0, 0, 1, -1};
            int dy[4] = {1, -1, 0, 0};
    
            while(!q.empty() && fresh >0){
                int size = q.size();
                for(int j = 0; j < size; j++){
                    int x = q.front().first, y = q.front().second;
                    q.pop();
    
                    //check all 4 directions
                    for(int i = 0; i < 4; i++){
                        int new_x = x + dx[i] , new_y = y + dy[i];
                        if(new_x < 0 || new_y < 0 || new_x >= rows || new_y >= cols || grid[new_x][new_y] != 1) continue;
                        grid[new_x][new_y] = 2; //if fresh make rotten
                        q.push({new_x, new_y});
                        fresh--;
                    }
                }
                time++;
            }
            return fresh == 0? time : -1;
        }
    };