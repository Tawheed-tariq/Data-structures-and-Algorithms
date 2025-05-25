class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0, right = 0;
        int maxLen = 0, temp = k;

        while(right < nums.size() && left < nums.size()){
            if(nums[right] == 0){
                if(temp > 0){
                    temp--;
                    right++;
                }else{
                    maxLen = max(maxLen, right - left);
                    while(left < nums.size() && nums[left] == 1)
                        left++;
                    temp++;
                    left++;
                }
            }else{
                right++;
            }
        }
        maxLen = max(maxLen, right - left);
        return maxLen;
    }
};