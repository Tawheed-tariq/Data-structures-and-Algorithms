class Solution {
    public:
        int findTargetSumWays(vector<int>& nums, int target) {
            int sum = accumulate(nums.begin(), nums.end(), 0);
            return sum < abs(target - 0) || (sum + target)%2 != 0 ? 0 : subsetSum(nums, (sum + target) >> 1);
        }
    
        int subsetSum(vector<int>& nums, int target){
            vector<int> dp(target + 1, 0);
            dp[0] = 1; //to make a target of 0 we have one subset
            for(int &num: nums){
                for(int i = target; i >= num; i--){
                    dp[i] += dp[i-num];
                }
            }
            return dp[target];
        }
    };