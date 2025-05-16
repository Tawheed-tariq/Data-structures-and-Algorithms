class Solution {
    public:
        bool isSafe(int row, int col, vector<vector<char>>& board, char c){
            for(int i = 0; i < 9; i++){
                //check for row
                if(board[row][i] == c)
                    return false;
                //check for col
                if(board[i][col] == c)
                    return false;
                //check for 3x3 box
                if(board[3*(row/3) + i/3][3*(col/3) + i%3] == c)
                    return false;
            }
            return true;
        }
        bool solve(vector<vector<char>>& board){
            int n = board[0].size();
            for(int row = 0; row < n; row++){
                for(int col = 0; col < n; col++){
                    if(board[row][col] == '.'){
                        for(char c = '1'; c <= '9'; c++){
                            if(isSafe(row, col, board, c)){
                                board[row][col] = c;
    
                                if(solve(board)){
                                    //if solution is possible 
                                    return true;
                                }else{
                                    //backtrack
                                    board[row][col] = '.';
                                }
                            }
                        }
                        return false;
                    }
                }
            }
            return true;
        }
        void solveSudoku(vector<vector<char>>& board) {
            solve(board);
        }
    };