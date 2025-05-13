// https://www.youtube.com/watch?v=Ew_R-ZfhPEc
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int effectiveBuy = prices[0];
        int profit = 0;

        for(int i = 0; i < prices.size(); i++){
            profit = max(profit, prices[i] - effectiveBuy - fee);
            effectiveBuy = min(effectiveBuy, prices[i] - profit);
        }
        return profit;
    }
};