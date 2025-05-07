class Solution {
    public:
        void solve(vector<int>& nums,int ind, int target, int &cnt){
            if(ind == nums.size()){
                if(target == 0) cnt++;
                return;
            }
    
            solve(nums, ind+1, target - nums[ind], cnt);
            solve(nums, ind+1, target + nums[ind], cnt);
        }
        int findTargetSumWays(vector<int>& nums, int target) {
            int cnt = 0;
            solve(nums, 0, target, cnt);
            return cnt;
        }
    };