class Solution {
    public:
        int solve(vector<int>& cost, int step){
            if(step >= cost.size()) return 0;
    
            int one = solve(cost, step+1);
            int two = solve(cost, step+2);
    
            return min(one, two) + cost[step];
        }
        int minCostClimbingStairs(vector<int>& cost) {
            return min(solve(cost, 0), solve(cost, 1));
        }
    };