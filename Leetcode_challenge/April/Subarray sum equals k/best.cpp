class Solution {
    public:
        int subarraySum(vector<int>& nums, int k) {
            unordered_map<int, int> prefix_sum;
            int currSum = 0, count  = 0;
            for(int i =0; i < nums.size(); i++){
                currSum += nums[i];
    
                if(currSum == k){
                    count++;
                }
                if(prefix_sum.find(currSum -k) != prefix_sum.end())
                    count += prefix_sum[currSum - k];
    
                prefix_sum[currSum]++;
            }
            return count;
        }
    };