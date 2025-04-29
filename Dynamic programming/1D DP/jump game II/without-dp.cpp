class Solution {
    public:
        int jump(vector<int>& nums, int pos = 0) {
            if(pos >= nums.size() - 1) return 0;
            int minJumps = INT_MAX -1 ;
            for(int i = 1; i <= nums[pos]; i++){
                minJumps = min(minJumps, 1+jump(nums, pos+i));
            }
            return minJumps;
        }
    };