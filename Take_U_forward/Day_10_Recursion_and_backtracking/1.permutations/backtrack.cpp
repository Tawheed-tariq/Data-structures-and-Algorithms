class Solution {
    public:
        void recPerm(int ind, vector<int> &nums, vector<vector<int>> &ans){
            if(ind == nums.size() - 1){
                ans.push_back(nums);
                return;
            }
    
            for(int i = ind; i < nums.size(); i++){
                swap(nums[ind], nums[i]);
                recPerm(ind+1, nums, ans);
                swap(nums[ind], nums[i]);
            }
        }
        vector<vector<int>> permute(vector<int>& nums) {
            vector<vector<int>> ans;
            recPerm(0, nums, ans);
            return ans;
        }
    };