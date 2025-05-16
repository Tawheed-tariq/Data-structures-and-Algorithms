class Solution {
    public:
      int solve(int i, int j, vector<int> &arr, vector<vector<int>> &dp){
          if(i == j) return 0;
          if(dp[i][j] != -1) return dp[i][j];
          int ans = INT_MAX;
          for(int k = i; k < j;k++){
              ans = min(ans, solve(i, k, arr, dp) + solve(k+1, j, arr, dp) + arr[i-1]*arr[k]*arr[j]);
          }
          return dp[i][j] = ans;
      }
      int matrixMultiplication(vector<int> &arr) {
          vector<vector<int>> dp(arr.size(), vector<int>(arr.size(), -1));
          return solve(1, arr.size()-1, arr, dp);
      }
  };