class Solution {
    public:
        void addSol(vector<vector<string>> &ans, vector<vector<int>> &board, int n){
            vector<string> temp;
            for(int i = 0; i < n; i++){
                string str = "";
                for(int j = 0; j < n;j++){
                    if(board[i][j] == 1)
                        str.push_back('Q');
                    else
                        str.push_back('.');
                }
                temp.push_back(str);
            }
            ans.push_back(temp);
        }
    
        bool isSafe(int row, int col, vector<vector<int>> &board, int n){
            //check for row
            int x = row, y = col;
            while(y >= 0){
                if(board[x][y] == 1)
                    return false;
                y--;
            }
    
            //check for upper diagnol
            x = row, y = col;
            while(x >= 0 && y >= 0){
                if(board[x][y] == 1)
                    return false;
                x--;
                y--;
            }
    
            //check for lower diagnol
            x = row, y = col;
            while(x < n && y >= 0){
                if(board[x][y] == 1)
                    return false;
                x++;
                y--;
            }
    
            return true;
        }
        void solve(int col, vector<vector<string>> &ans, vector<vector<int>> &board, int n){
            if(col == n){
                addSol(ans, board, n);
                return;
            }
    
            for(int row= 0; row < n; row++){
                if(isSafe(row, col, board, n)){
                    board[row][col] = 1;
                    solve(col+1, ans, board, n);
                    //backtrack
                    board[row][col] = 0;
                }
            }
        }
        vector<vector<string>> solveNQueens(int n) {
            vector<vector<int>> board(n, vector<int>(n, 0));
            vector<vector<string>> ans;
    
            solve(0, ans, board, n);
            return ans;
        }
    };