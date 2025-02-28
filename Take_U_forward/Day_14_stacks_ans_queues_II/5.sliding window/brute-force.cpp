class Solution {
    public:
        vector<int> maxSlidingWindow(vector<int>& nums, int k) {
            vector<int> ans;
            int n = nums.size();
            for(int i = 0; i+k <= n; i++){
                int maxVal = INT_MIN;
                for(int j = i; j < i+k; j++){
                    maxVal = max(maxVal, nums[j]);
                }
                ans.push_back(maxVal);
            }
            return ans;
        }
    };