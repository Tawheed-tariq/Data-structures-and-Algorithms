class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            int best = 0;
            for(int i = 0; i < prices.size(); i++){
                for(int j = i+1; j < prices.size(); j++){
                    best = max(best, prices[j] - prices[i]);
                }
            }
            return best;
        }
    };