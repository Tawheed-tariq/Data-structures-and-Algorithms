class Solution {
    public:
        int solve(vector<int> &nums, int n, int ind, int prev_ind){
            if(ind == n) return 0;
    
            int notTake = 0 + solve(nums, n, ind+1, prev_ind);
            int take = 0;
            if(prev_ind == -1 || nums[ind] > nums[prev_ind])
                take = 1 + solve(nums, n, ind+1, ind);
            return max(notTake, take);
        }
        int lengthOfLIS(vector<int>& nums) {
            return solve(nums, nums.size(), 0, -1);
        }
    };