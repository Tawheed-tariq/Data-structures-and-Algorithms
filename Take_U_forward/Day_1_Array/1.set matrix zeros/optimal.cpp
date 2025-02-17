class Solution {
    public:
        void setZeroes(vector<vector<int>>& matrix) {
            int m = matrix.size();
            int n = matrix[0].size();
            vector<pair<int,int>> p;
    
            for(int i =0 ; i < m*n; i++){
                int row = i/n, col = i%n;
                if(matrix[row][col] == 0)
                    p.push_back({row, col});
            }
    
            for(auto x:p){
                for(int i = 0; i < n; i++){
                    matrix[x.first][i] = 0;
                }
                for(int i = 0; i < m; i++){
                    matrix[i][x.second] = 0;
                }
            }
        }
    };