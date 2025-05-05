class Solution {
    public:
        int solve(int i, int j, vector<vector<int>>& triangle, vector<vector<int>>& dp){
            if(i == triangle.size())
                return 0;
            if(dp[i][j] != -1) return dp[i][j];
            int take_j = solve(i+1, j, triangle, dp);
            int take_j_1 = solve(i+1, j+1, triangle, dp);
    
            return dp[i][j] = triangle[i][j] + min(take_j, take_j_1);
        }
        int minimumTotal(vector<vector<int>>& triangle) {
            vector<vector<int>> dp(triangle.size()+1, vector<int>(triangle.size()+1, -1));
            return solve(0, 0, triangle, dp);
        }
    };