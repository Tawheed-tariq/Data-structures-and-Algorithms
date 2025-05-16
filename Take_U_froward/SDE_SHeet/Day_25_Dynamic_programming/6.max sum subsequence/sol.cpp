class Solution {
    public:
      int solve(vector<int> &nums, int n, int ind, int prev_ind, vector<vector<int>> &dp){
          if(ind == n) return 0;
  
          if(dp[ind][prev_ind+1] != -1)
              return dp[ind][prev_ind +1];
  
          int notTake = solve(nums, n, ind+1, prev_ind,dp);
          int take = 0;
          if(prev_ind == -1 || nums[ind] > nums[prev_ind])
              take = nums[ind] + solve(nums, n, ind+1, ind, dp);
          return dp[ind][prev_ind +1] = max(notTake, take);
      }
      int maxSumIS(vector<int>& nums) {
          vector<vector<int>> dp(nums.size(), vector<int>(nums.size()+1, -1));  //(0,0) will represent (0, -1) => (curr_ind, prev_ind) and similarly
          return solve(nums, nums.size(), 0, -1, dp);
      }
  };