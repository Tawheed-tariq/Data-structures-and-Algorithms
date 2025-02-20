class Solution {
    public:
        void subsets(int i, vector<int> &arr, set<vector<int>> &res, vector<int> subset){
            if(i == arr.size()){
                sort(subset.begin(), subset.end());
                res.insert(subset);
                return;
            }
    
            subset.push_back(arr[i]);
            subsets(i+1, arr, res, subset);
    
            subset.pop_back();
            subsets(i+1, arr, res, subset);
        }
        vector<vector<int>> subsetsWithDup(vector<int>& nums) {
            set<vector<int>> res;
            vector<int> subset;
            subsets(0, nums, res, subset);
            vector<vector<int>> ans;
            for(auto x:res){
                ans.push_back(x);
            }
            return ans;
        }
    };