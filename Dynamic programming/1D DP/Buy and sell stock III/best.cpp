class Solution {
public:
    int find_max_profit(int strt, int end, vector<int> &prices){
        int buy = INT_MAX, profit = 0;
        for(int i = strt; i <= end; i++){
            buy = min(buy, prices[i]);
            profit = max(profit, prices[i]-buy);
        }
        return profit;
    }
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        //divide the array into two parts and first transaction in the first part and second transaction in the second part
        for(int i = 0; i < prices.size(); i++){
            int left = find_max_profit(0, i-1, prices);
            int right = find_max_profit(i, prices.size()-1, prices);
            profit = max(profit, left+right);
        }
        return profit;
    }
};