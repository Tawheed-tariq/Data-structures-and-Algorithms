class Solution {
    public:
        int solve(vector<int>& coins, int amount, vector<int> &dp){
            if(amount == 0)
                return 0;
            if(amount < 0) return INT_MAX;
    
            if(dp[amount] != -1) return dp[amount];
    
            int mini = INT_MAX;
            for(int &coin: coins){
                int ans = solve(coins, amount - coin, dp);
                if(ans != INT_MAX) mini = min(mini, 1+ ans); //utilize currect coin
            }
            return dp[amount] = mini;
        }
        int coinChange(vector<int>& coins, int amount) {
            vector<int> dp(amount+1, -1);
            int ans= solve(coins, amount, dp);
            return ans != INT_MAX? ans : -1;
        }
    };