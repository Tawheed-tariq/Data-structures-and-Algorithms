class Solution {
    public:
      void subsets(int i, vector<int> &arr, vector<int> &res, int sum){
          if(i == arr.size()){
              res.push_back(sum);
              return;
          }
          
          //include element
          subsets(i+1, arr, res, sum + arr[i]);
          
          //exclude element
          subsets(i+1, arr, res, sum);
      }
      vector<int> subsetSums(vector<int>& arr) {
          vector<int> res;
          subsets(0, arr, res, 0);
          return res;
      }
  };