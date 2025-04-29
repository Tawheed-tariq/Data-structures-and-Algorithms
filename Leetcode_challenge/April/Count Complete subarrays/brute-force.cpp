class Solution {
    public:
        int countCompleteSubarrays(vector<int>& nums) {
            int k = unordered_set<int>(nums.begin(), nums.end()).size();
            int n = nums.size();
            int count = 0;
            for(int i = 0; i < n; i++){
                unordered_set<int> temp;
                for(int j = i; j < n; j++){
                    temp.insert(nums[j]);
                    if(temp.size() == k) count++;
                }  
            }
            return count;
        }
    };