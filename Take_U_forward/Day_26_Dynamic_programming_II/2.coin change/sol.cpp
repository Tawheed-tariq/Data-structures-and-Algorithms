class Solution {
    public:
        int coinChange(vector<int>& coins, int amount) {
            vector<int> dp(amount + 1, amount + 1); //dp[i] represents the minimum number of coins required to make the amount i.
            //Fill the dp array with a large value (amount + 1), as we want to find the minimum.
    
            dp[0] = 0;
    
            for(int i = 1; i <= amount; i++){
                for(auto coin : coins){
                    if(i - coin >= 0)
                        dp[i] = min(dp[i], dp[i-coin]+1);
                }
            }
            return (dp[amount] > amount) ? -1 : dp[amount];
        }
    };