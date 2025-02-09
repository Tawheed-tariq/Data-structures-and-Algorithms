class Solution {
    public:
        void transpose(vector<vector<int>> &mat){
            int n = mat.size();
            for(int i = 0; i < n*n; i++){
                int row = i/n, col = i%n;
                if(col > row){
                    swap(mat[row][col], mat[col][row]);
                }
            }
        }
        void rotate(vector<vector<int>>& matrix) {
            int i = 0, j = matrix.size() - 1;
            while(i < j){
                swap(matrix[i], matrix[j]);
                i++;
                j--;
            }
            transpose(matrix);
        }
    };