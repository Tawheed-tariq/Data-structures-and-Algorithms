class Solution {
    public:
        int countSubarrays(vector<int>& nums) {
            int left = 0;
            int right = 2;
            int count = 0;
            while(right < nums.size()){
                count = (nums[left]+nums[right])*2 == nums[right-1]? ++count : count;
                left++;
                right++;
            }
            return count;
        }
    };