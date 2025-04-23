class Solution {
    public:
        int rob(vector<int>& nums) {
            int n = nums.size();
            int i_2 = 0, i_1 = nums[0];
            
            for(int i = 1; i < n; i++){
                int rob_house = nums[i] + i_2;
                int dont_rob = i_1;
                int curr = max(rob_house, dont_rob);
                i_2 = i_1;
                i_1 = curr;
            }
            return i_1; 
        }
    };