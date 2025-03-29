class Solution {
    public:
        int solve(int strt, int end, vector<int> &cuts, int left, int right, vector<vector<int>> &dp){
            if(left > right) return 0;
            if(dp[left][right] != -1) return dp[left][right];
    
            int cost = 1e9;
            for(int i = left; i<= right; i++){
                int left_cost = solve(strt, cuts[i], cuts, left, i-1, dp);
                int right_cost = solve(cuts[i], end, cuts, i+1, right, dp);
                int curr_cost = (end-strt) + left_cost + right_cost;
                cost = min(cost, curr_cost);
            }
    
            return dp[left][right] = cost;
        }
        int minCost(int n, vector<int>& cuts) {
            vector<vector<int>> dp(cuts.size() +1, vector<int>(cuts.size()+1, -1));
            sort(cuts.begin(), cuts.end());
            return solve(0, n, cuts, 0, cuts.size() - 1, dp);
        }
    };