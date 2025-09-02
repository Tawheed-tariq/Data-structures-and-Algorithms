class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size(), n = maze[0].size();

        queue<vector<int>> q;
        q.push({entrance[0], entrance[1], 0});
        maze[entrance[0]][entrance[1]] = '+'; //mark visited

        while(!q.empty()){
            auto top = q.front();
            q.pop();

            int x = top[0], y = top[1], steps = top[2];

            if((x == 0 || x == m-1 || y == 0 || y == n-1) && !(x == entrance[0] && y == entrance[1]))
                return steps;

            if(x+1 < m && maze[x+1][y] == '.'){
                maze[x+1][y] = '+';
                q.push({x+1, y, steps+1});
            }

            if(x-1 >= 0 && maze[x-1][y] == '.'){
                maze[x-1][y] = '+';
                q.push({x-1, y, steps+1});
            }

            if(y+1 < n && maze[x][y+1] == '.'){
                maze[x][y+1] = '+';
                q.push({x, y+1, steps+1});
            }

            if(y-1 >= 0 && maze[x][y-1] == '.'){
                maze[x][y-1] = '+';
                q.push({x, y-1, steps+1});
            }
        }
        return -1;
    }
};