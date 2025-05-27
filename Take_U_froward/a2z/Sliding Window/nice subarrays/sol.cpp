class Solution {
public:
    int solve(vector<int>& nums, int k){
        int left = 0, count = 0;

        for(int right = 0; right < nums.size(); right++){
            if(nums[right] % 2 != 0)
                k--;

            while(k < 0)
                k += nums[left++] % 2;

            count += right - left + 1; 
        }
        return count;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        int sum1 = solve(nums, k), sum2 = solve(nums, k- 1);
        return sum1 - sum2;
    }
};