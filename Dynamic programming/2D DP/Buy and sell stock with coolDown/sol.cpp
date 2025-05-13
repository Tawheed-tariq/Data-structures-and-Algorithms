class Solution {
public:
    int max_profit(vector<int> &prices, int pos, bool brought, vector<vector<int>> &dp){
        if(pos >= prices.size()) return 0;

        if(dp[brought][pos] != -1) return dp[brought][pos];

        int skip = max_profit(prices, pos+1, brought, dp);
        int profit = 0;
        if(brought){
            profit = max(skip, max_profit(prices, pos+2, !brought, dp)+prices[pos]);
        }else{
            profit = max(skip, max_profit(prices, pos+1, !brought, dp) - prices[pos]);
        }

        return dp[brought][pos] = profit;
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(2, vector<int>(prices.size()+1, -1));
        return max_profit(prices, 0, false, dp);
    }
};