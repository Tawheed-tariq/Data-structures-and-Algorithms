class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rows = 9, cols = 9;
        unordered_map<char, bool> mp;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(mp[board[i][j]] && board[i][j] != '.') return false;
                mp[board[i][j]] = true;
            }
            mp.clear();
        }

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(mp[board[j][i]] && board[j][i] != '.') return false;
                mp[board[j][i]] = true;
            }
            mp.clear();
        }

        for (int boxRow = 0; boxRow < 3; boxRow++) {
        for (int boxCol = 0; boxCol < 3; boxCol++) {
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    int row = boxRow * 3 + i;
                    int col = boxCol * 3 + j;
                    if(mp[board[row][col]] && board[row][col] != '.') return false;
                    mp[board[row][col]] = true;
                }
            }
            mp.clear();
        }
    }
        return true;
    }
};