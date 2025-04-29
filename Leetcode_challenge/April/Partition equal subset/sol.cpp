class Solution {
    public:
        bool canPartition(vector<int>& nums) {
            int total_sum = accumulate(nums.begin(), nums.end(), 0);
            if(total_sum & 1) return false; //total sum is odd , hence cannot be divided in 2 halves
            vector<bool> dp(total_sum/2 +1, false);
            dp[0] = true; // if sum is 0 then true
            for(int num: nums){
                for(int j = total_sum/2; j >= num; j--){
                    if(dp[j-num]) dp[j] = true;
                }
            }
            return dp[total_sum/2];
        }
    };