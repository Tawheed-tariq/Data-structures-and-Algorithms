class Solution {
    public:
        int countSubarrays(vector<int>& nums) {
            int left = 0;
            int right = 2;
            int count = 0;
            while(right < nums.size()){
                count = (float)(nums[left]+nums[right]) == (float)nums[right-1]/2? ++count : count;
                left++;
                right++;
            }
            return count;
        }
    };