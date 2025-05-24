class Solution {
public:

    vector<vector<int>>directions{{0,1},{1,0},{0,-1},{-1,0}};
    int m , n;

    bool solve(vector<vector<char>>& board, string word, int i, int j, int idx){
        if(idx == word.size()) return true;

        if(i < 0 || i >= m || j < 0 || j >= n || board[i][j] == '$' || board[i][j] != word[idx])
            return false;

        char ch = board[i][j];
        board[i][j] = '$';

        for(auto &dir: directions){
            int i_ = i + dir[0];
            int j_ = j  + dir[1];

            if(solve(board, word, i_, j_, idx+1)) return true;
        }

        board[i][j] = ch;
        return false;
    }


    bool exist(vector<vector<char>>& board, string word) {
        m = board.size(), n = board[0].size();

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == word[0] && solve(board, word, i, j, 0))
                    return true;
            }
        }
        return false;
    }
};