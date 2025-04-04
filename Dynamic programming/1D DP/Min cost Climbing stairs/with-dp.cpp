class Solution {
    public:
        int solve(vector<int>& cost, int step, vector<int> &dp){
            if(step >= cost.size()) return 0;
    
            if(dp[step] != -1) return dp[step];
    
            int one = solve(cost, step+1, dp);
            int two = solve(cost, step+2, dp);
    
            return dp[step] = min(one, two) + cost[step];
        }
        int minCostClimbingStairs(vector<int>& cost) {
            vector<int> dp(cost.size() + 1, -1);
            return min(solve(cost, 0, dp), solve(cost, 1, dp));
        }
    };