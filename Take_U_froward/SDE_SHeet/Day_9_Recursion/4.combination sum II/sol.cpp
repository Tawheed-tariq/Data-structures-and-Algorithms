class Solution {
    public:
        void func(vector<int>& arr, vector<vector<int>> &res, vector<int> &subArr, int i, int target){
            if(target == 0){
                res.push_back(subArr);
                return;
            }
                
            for(int j = i; j < arr.size(); j++){
                if(j > i && arr[j] == arr[j-1]) continue;
                if(arr[j] > target) break;
    
                subArr.push_back(arr[j]);
                func(arr, res, subArr, j+1, target-arr[j]);
                subArr.pop_back();
            }
            
        }
        vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
            vector<vector<int>> res;
            vector<int> subArr;
            sort(candidates.begin(), candidates.end());
            func(candidates, res, subArr, 0, target);
            return res;
        }
    };