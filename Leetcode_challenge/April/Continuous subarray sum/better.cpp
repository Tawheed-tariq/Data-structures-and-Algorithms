class Solution {
    public:
        bool checkSubarraySum(vector<int>& nums, int k) {
            unordered_map<int, int> prefix_sum;
            prefix_sum[0] = -1;
            int sum = 0;
            for(int i = 0; i < nums.size(); i++){
                sum += nums[i];
                if(prefix_sum.find(sum % k) != prefix_sum.end()){
                    if(i - prefix_sum[sum %k] >= 2)
                        return true;
                }
                else{
                    prefix_sum[sum % k] = i;
                }
            }
            return false;
        }
    };