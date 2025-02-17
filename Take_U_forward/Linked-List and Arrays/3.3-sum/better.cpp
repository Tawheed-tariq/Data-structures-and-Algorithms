class Solution {
    public:
        vector<vector<int>> threeSum(vector<int>& nums) {
            sort(nums.begin(), nums.end());
            int n = nums.size();
            vector<vector<int>> ans;
            for(int i = 0; i < n - 2; i++){
                int newTarget = 0 - nums[i];
                int low = i+1, high = n-1;
                while(low < high){
                    if(nums[low] + nums[high] > newTarget)
                        high--;
                    else if(nums[low] + nums[high] < newTarget)
                        low++;
                    else{
                        ans.push_back({nums[i], nums[low], nums[high]});
                        int temp1 = low, temp2 = high;
                        while(low < high && nums[low] == nums[temp1]) low++;
                        while(low < high && nums[high] == nums[temp2]) high--;
                    }
                }
                while(i+1 < n && nums[i] == nums[i+1]) i++;
            }
            return ans;
        }
    };