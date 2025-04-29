class Solution {
    public:
        long long maximumTripletValue(vector<int>& nums) {
            long long max_result = 0;
            int max_val = nums[0], max_diff = 0;
            int n = nums.size();
            if(n < 3) return max_result;
            for(int i = 0; i < n; i++){
                max_result = max(max_result, (long long) max_diff * nums[i]);
    
                max_diff = max(max_diff, max_val - nums[i]);
    
                max_val = max(max_val, nums[i]);
            }
            return max_result;
        }
    };