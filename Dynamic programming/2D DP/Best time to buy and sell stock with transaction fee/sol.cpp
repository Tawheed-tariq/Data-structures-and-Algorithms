class Solution {
public:
    int max_profit(vector<int> &prices, int pos, int fee, bool brought, vector<vector<int>> &dp){
        if(pos >= prices.size()) return 0;

        if(dp[brought][pos] != -1) return dp[brought][pos];

        int skip = max_profit(prices, pos+1, fee, brought, dp);
        int profit = 0;
        if(brought){
            profit = max(skip, max_profit(prices, pos+1, fee, !brought, dp)+prices[pos]-fee);
        }else{
            profit = max(skip, max_profit(prices, pos+1, fee, !brought, dp) - prices[pos]);
        }

        return dp[brought][pos] = profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>> dp(2, vector<int>(prices.size()+1, -1));
        return max_profit(prices, 0, fee, false, dp);
    }
};