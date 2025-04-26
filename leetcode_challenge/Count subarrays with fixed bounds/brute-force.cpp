class Solution {
    public:
        long long countSubarrays(vector<int>& nums, int minK, int maxK) {
            int count = 0;
            for(int i = 0; i < nums.size(); i++){
                int minval = INT_MAX, maxval = INT_MIN;
                for(int j = i; j < nums.size(); j++){
                    minval = min(minval, nums[j]);
                    maxval = max(maxval, nums[j]);
                    if(minval == minK && maxval == maxK){
                        count++;
                    }
                }
            }
            return count;
        }
    };