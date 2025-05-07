class Solution {
    public:
        bool canPartition(vector<int>& nums) {
            int total_sum = accumulate(nums.begin(), nums.end(), 0);
            if(total_sum & 1) return false; //total sum is odd , hence cannot be divided in 2 halves
            vector<bool> dp(total_sum/2 +1, false);
            // dp[i] = true means a subset with sum i is possible
            dp[0] = true; // because a sum of 0 is always possible with an empty subset
            for(int num: nums){
                for(int j = total_sum/2; j >= num; j--){
                    if(dp[j-num]) dp[j] = true;
                }
            }
            return dp[total_sum/2];
        }
    };