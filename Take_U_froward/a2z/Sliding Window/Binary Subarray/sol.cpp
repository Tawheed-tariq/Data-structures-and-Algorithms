class Solution {
public:

    int solve(vector<int>& nums, int goal){
        if(goal < 0) return 0;
        int left = 0, right = 0, sum = 0, res = 0;

        while(right < nums.size()){
            sum += nums[right];

            while(sum > goal)
                sum -= nums[left++];

            if(sum <= goal) res += right - left +1; //number of subarrays

            right++;
        }
        return res;
        
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int sum1 = solve(nums, goal); // find subarrays <= goal
        int sum2 = solve(nums, goal - 1); //find subarrays <= goal -1;

        return sum1- sum2;
    }
};