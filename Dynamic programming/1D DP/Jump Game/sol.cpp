// https://www.youtube.com/watch?v=muDPTDrpS28
class Solution {
    public:
        bool canJump(vector<int>& nums) {
            int n =nums.size(), reachable = 0;
            for(int i = 0; i < n; i++){
                if(reachable < i)
                    return false;
                reachable = max(reachable, i+nums[i]); 
            }
            
            return true;
        }
    };