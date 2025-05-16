class Solution {
    public:
        int longestConsecutive(vector<int>& nums) {
            if (nums.size() == 0) return 0;
            sort(nums.begin(), nums.end());
            int lastSmaller = INT_MIN;
            int count = 0;
            int longest = 1;
            for(int i = 0; i < nums.size(); i++){
                if(nums[i] == lastSmaller +1){
                    count++;
                    lastSmaller = nums[i];
                }else if(i > 0 && nums[i] == nums[i-1]){
                    continue;
                }else{
                    count = 1;
                    lastSmaller = nums[i];
                }
                longest = max(longest, count);
            }
            return longest;
        }
    };