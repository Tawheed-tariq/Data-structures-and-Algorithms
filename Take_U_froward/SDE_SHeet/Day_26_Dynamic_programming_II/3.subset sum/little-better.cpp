class Solution {
    public:
        bool solve(vector<int>& nums, int sum, int i = 0){
            if(sum == 0) return true;
            if(i >= nums.size() || sum < 0) return false;
            return solve(nums, sum - nums[i], i+1) || solve(nums,sum, i+1);
        }
        bool canPartition(vector<int>& nums) {
            int total_sum = accumulate(nums.begin(), nums.end(), 0);
            if(total_sum & 1) return false; //total sum is odd , hence cannot be divided in 2 halves
            return solve(nums, total_sum/2);
        }
    };