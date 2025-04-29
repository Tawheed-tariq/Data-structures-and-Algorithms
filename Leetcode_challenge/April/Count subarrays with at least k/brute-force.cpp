class Solution {
    public:
        long long countSubarrays(vector<int>& nums, int k) {
            int maxi = INT_MIN;
            for(int i = 0; i < nums.size(); i++){
                maxi = max(maxi, nums[i]);
            }
            int res = 0, n= nums.size();
            for(int i = 0; i < nums.size(); i++){
                int count = 0;
                for(int j = i; j < nums.size(); j++){
                    if(nums[j] == maxi) count++;
                    if(count >= k){
                        res+= n-j;
                        break;
                    }
                }
            }
            return res;
        }
    };