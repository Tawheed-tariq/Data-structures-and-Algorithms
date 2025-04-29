class Solution {
    public:
        long long countSubarrays(vector<int>& nums, long long k) {
            long long count = 0;
            for(int i = 0; i < nums.size(); i++){
                long long sum = 0;
                for(int j = i; j < nums.size(); j++){
                    sum += nums[j];
                    if(sum*(j-i+1) < k) count++;
                }
            }
            return count;
        }
    };