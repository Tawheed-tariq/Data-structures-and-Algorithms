class Solution {
    public:
        
        int climbStairs(int n) {
            vector<int> dp(n+1, -1);
            dp[0] = 1; //do nothing hence one way
            dp[1] = 1; //take one step hence one way
    
            for(int i = 2; i <= n; i++){
                dp[i] = dp[i-1] + dp[i-2];
            }
            return dp[n];
        }
    };