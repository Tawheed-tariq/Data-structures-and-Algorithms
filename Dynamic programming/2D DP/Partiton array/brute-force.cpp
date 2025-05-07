class Solution {
    public:
        int solve(vector<int>& nums, int ind, int sum, int n, int total_sum){
            if(n == nums.size()/2){
                int remaining_sum = total_sum - sum;
                return abs(remaining_sum - sum);
            }
    
            if(ind >= nums.size()) return INT_MAX;
    
            int select = solve(nums, ind+1, sum + nums[ind], n+1, total_sum);
            int not_select = solve(nums, ind+1, sum, n, total_sum);
    
            return min(select, not_select);
        }
        int minimumDifference(vector<int>& nums) {
            int total_sum = accumulate(nums.begin(), nums.end(), 0);
            return solve(nums, 0, 0, 0, total_sum);
        }
    };