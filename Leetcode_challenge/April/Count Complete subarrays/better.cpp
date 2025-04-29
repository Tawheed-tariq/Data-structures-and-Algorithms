class Solution {
    public:
        int countCompleteSubarrays(vector<int>& nums, int left = 0) {
            int k = unordered_set<int>(nums.begin(), nums.end()).size();
            int n = nums.size();
            int count = 0;
            unordered_map<int, int> mp;
            for(int i = 0; i < n; i++){
                 mp[nums[i]]++;
                 while(mp.size() == k){
                    count += nums.size() - i;
                    mp[nums[left]]--;
                    if(mp[nums[left]] == 0) mp.erase(nums[left]);
                    left++;
                 }
            }
            return count;
        }
    };