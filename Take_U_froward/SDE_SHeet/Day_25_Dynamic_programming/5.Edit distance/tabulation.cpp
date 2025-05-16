class Solution {
    public:
        int solve(int i, int j, string word1, string word2, vector<vector<int>> &dp){
            if(j == 0) return i;
            if(i == 0) return j;
    
            if(dp[i][j] != -1) return dp[i][j];
            if(word1[i-1] == word2[j-1]) return dp[i][j] = solve(i-1, j-1, word1, word2, dp);
    
            int ans = INT_MAX;
            ans = min(ans, 1+solve(i-1, j-1, word1, word2, dp));
            ans = min (ans, 1+solve(i, j-1, word1, word2, dp));
            ans = min(ans, 1+solve(i-1, j, word1, word2, dp));
    
            return dp[i][j] = ans;
        }
        int minDistance(string word1, string word2) {
            int n1 = word1.size(), n2 = word2.size();
            vector<vector<int>> dp(n1+1, vector<int>(n2+1, -1));
            return solve(n1, n2, word1, word2, dp);
        }
    };