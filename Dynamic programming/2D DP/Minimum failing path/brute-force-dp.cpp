class Solution {
    public:
        int solve(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp){
            if(i == matrix.size()) return 0;
    
            if(dp[i][j] != -100000) return dp[i][j];
    
            int ans = matrix[i][j] + solve(i+1, j, matrix, dp);
            if(j-1 >= 0)
                ans = min(matrix[i][j] + solve(i+1, j-1, matrix, dp), ans);
    
            if(j+1 < matrix.size())
                ans = min(matrix[i][j] + solve(i+1, j+1, matrix, dp), ans);
    
            return dp[i][j] = ans;
        }
        int minFallingPathSum(vector<vector<int>>& matrix) {
            vector<vector<int>> dp(matrix.size(), vector<int>(matrix.size(), -100000));
            int ans = INT_MAX;
    
            for(int i =0; i < matrix.size(); i++){
                ans = min(ans, solve(0, i, matrix, dp));
            }
            return ans;
        }
    };