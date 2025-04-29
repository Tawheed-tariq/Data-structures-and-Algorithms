// https://www.youtube.com/watch?v=BTk6_WBc4Ig
class Solution {
    public:
        long long countSubarrays(vector<int>& nums, int minK, int maxK) {
            long long count = 0;
            int invalid_idx = -1, min_idx = -1, max_idx = -1;
            for(int i = 0; i < nums.size(); i++){
                if(nums[i] < minK || nums[i] > maxK) invalid_idx = i;
    
                if(nums[i] == minK) min_idx = i;
                if(nums[i] == maxK) max_idx = i;
    
                count += max(min(min_idx, max_idx) - invalid_idx, 0);
            }
            return count;
        }
    };