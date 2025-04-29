class Solution {
    public:
        long long countFairPairs(vector<int>& nums, int lower, int upper) {
            int count = 0, n = nums.size();
            for(int i = 0; i < n; i++){
                for(int j = i+1; j < n; j++){
                    if(nums[i]+nums[j] >= lower && nums[i]+nums[j] <= upper)
                        count++;
                }
            }
            return count;
        }
    };