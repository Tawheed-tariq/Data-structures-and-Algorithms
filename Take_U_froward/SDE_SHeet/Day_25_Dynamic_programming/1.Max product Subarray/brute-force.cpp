class Solution {
    public:
        int maxProduct(vector<int>& nums) {
            int ans = nums[0];
            for(int i = 0; i < nums.size()-1; i++){
                int product = nums[i];
                for(int j = i+1; j < nums.size(); j++){
                    ans = max(ans, product);
                    ans = max(ans, nums[j]);
                    product *= nums[j];
                }   
                ans = max(ans, product);
            }
            return ans;
        }
    };