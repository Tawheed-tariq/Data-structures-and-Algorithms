class Solution {
    public:
        bool solve(vector<int>& nums, int i, int sum1, int sum2){
            if(i >= nums.size()) return sum1 == sum2;
            return solve(nums, i+1, sum1+nums[i], sum2) || solve(nums, i+1, sum1, sum2+nums[i]);
        }
        bool canPartition(vector<int>& nums) {
            return solve(nums, 0, 0, 0);
        }
    };