class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int i = 0, j = 0;

        while( i < m && j < n){
            if(i-1 >= 0 && mat[i-1][j] > mat[i][j])
                i = i-1;
            else if(j-1 >=0 && mat[i][j-1] > mat[i][j])
                j = j-1;
            else if(i+1 < m && mat[i+1][j] > mat[i][j])
                i = i+1;
            else if(j +1 < n && mat[i][j+1] > mat[i][j])
                j = j+1;
            else {
                return {i, j};
            }
        }
        return {-1, -1};
    }
};