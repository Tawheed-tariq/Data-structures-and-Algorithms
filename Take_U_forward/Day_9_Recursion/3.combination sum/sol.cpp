class Solution {
    public:
        void func(vector<int>& arr, vector<vector<int>> &res, vector<int> subArr, int i, int target){
            if(i == arr.size()){
                if(target == 0)
                    res.push_back(subArr);
                return;
            }
    
            if(arr[i] <= target){
                subArr.push_back(arr[i]);
                func(arr, res, subArr, i, target-arr[i]);
                subArr.pop_back();
            }
            func(arr, res, subArr, i+1, target);
        }
        vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
            vector<int> subArr;
            vector<vector<int>> res;
            func(candidates, res, subArr, 0, target);
            return res;
        }
    };