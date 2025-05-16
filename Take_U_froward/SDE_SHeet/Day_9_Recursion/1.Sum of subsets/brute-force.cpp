class Solution {
    public:
      void subsets(int i, vector<int> &arr, vector<vector<int>> &res, vector<int> subset){
          if(i == arr.size()){
              res.push_back(subset);
              return;
          }
          
          subset.push_back(arr[i]);
          subsets(i+1, arr, res, subset);
          
          subset.pop_back();
          subsets(i+1, arr, res, subset);
      }
      vector<int> subsetSums(vector<int>& arr) {
          vector<int> subset;
          vector<vector<int>> res;
          subsets(0, arr, res, subset);
          vector<int> ans;
          for(int i = 0; i < res.size(); i++){
              int sum = 0;
              for(auto x:res[i]){
                  sum+= x;
              }
              ans.push_back(sum);
          }
          return ans;
      }
  };