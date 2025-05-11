class Solution {
public:
    int max_profit(int ind, vector<int>& prices, bool buy, vector<int>& dp_buy, vector<int>& dp_sell){
        if(ind >= prices.size() || (buy && ind == prices.size()-1))
            return 0;
        else if(buy && dp_buy[ind] > 0)
            return dp_buy[ind];
        else if (!buy && dp_sell[ind] > 0)
            return dp_sell[ind];

        int profit = 0;
        int skip = max_profit(ind+1, prices, buy, dp_buy, dp_sell);

        if(buy){
            profit = max_profit(ind+1, prices, false, dp_buy, dp_sell) - prices[ind];
            dp_buy[ind] = max(skip, profit);
            return dp_buy[ind];
        }else{
            profit = max_profit(ind+1, prices, true, dp_buy, dp_sell) + prices[ind];
            dp_sell[ind] = max(skip, profit);
            return dp_sell[ind];
        }

        return max(profit, skip);
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> dp_buy(n,0),  dp_sell(n, 0);

        return max_profit(0, prices, true, dp_buy, dp_sell);
    }
};