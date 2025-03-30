class Solution {
    public:
  
      // Function to find minimum number of attempts needed in
      // order to find the critical floor.
      int solve(int n, int k, vector<vector<int>> &dp){
          if(n == 0) return 0;
          
          if(n == 1 || k == 0 || k == 1) return k;
          
          if(dp[n][k] != -1) return dp[n][k];
          
          int ans = INT_MAX;
          int low = 1, high = k;
          
          while(low <= high){
              int mid = low + (high-low)/2;
              int breakCase = solve(n-1, mid-1, dp); //egg breaks, check below
              int noBreak = solve(n, k-mid, dp); //egg doesnt break check above
              int step = 1 + max(breakCase, noBreak);
              ans = min(ans, step);
              
              if(breakCase > noBreak){
                  high = mid - 1; // Reduce the search space below mid
              }else{
                  low = mid+1; // Reduce the search space above mid
              }
          }
          
          return dp[n][k] = ans;
      }
      int eggDrop(int n, int k) {
          // code here
          vector<vector<int>> dp(n+1, vector<int>(k+1, -1));
          return solve(n, k, dp);
      }
  };