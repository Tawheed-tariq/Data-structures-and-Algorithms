class Solution {
    public:
        int findMaxConsecutiveOnes(vector<int>& nums) {
            int ones = 0;
            int ans = 0;
            for(int val:nums){
                if(val == 1)
                    ones++;
                else{
                    ans = max(ones, ans);
                    ones = 0;
                }
            }
            return max(ones, ans);
        }
    };