class Solution {
    public:
      int solve(int i, int j, vector<int> &arr){
          if(i == j) return 0;
          int ans = INT_MAX;
          for(int k = i; k < j;k++){
              ans = min(ans, solve(i, k, arr) + solve(k+1, j, arr) + arr[i-1]*arr[k]*arr[j]);
          }
          return ans;
      }
      int matrixMultiplication(vector<int> &arr) {
          // code here
          return solve(1, arr.size()-1, arr);
      }
  };
  