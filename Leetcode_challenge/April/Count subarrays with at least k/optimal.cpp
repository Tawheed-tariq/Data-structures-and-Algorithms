class Solution {
    public:
        long long countSubarrays(vector<int>& nums, int k) {
            int maxi = INT_MIN;
            for(int i = 0; i < nums.size(); i++){
                maxi = max(maxi, nums[i]);
            }
            long long res = 0;
            int n= nums.size(), count = 0;
            int left = 0, right = 0;
            for(; right < n; right++){
                if(nums[right] == maxi) count++;
                while(count >= k){
                    res += n - right;
                    if(nums[left] == maxi) count--;
                    left++;
                }
            }
            return res;
        }
    };