class Solution {
    public:
      int palPartition(string &s) {
          // code here
          int n= s.size();
          vector<vector<bool>> isPal(n, vector<bool>(n, false));
          vector<int> dp(n, -1);
          
          for(int gap = 0; gap < n; gap++){
              for(int i = 0, j = gap; j < n; j++, i++){
                  if(gap == 0){
                      isPal[i][j] = true;
                  }else if(gap == 1){
                      isPal[i][j] = (s[i] == s[j]);
                  }else{
                      isPal[i][j] = (s[i] == s[j] && isPal[i+1][j-1]);
                  }
              }
          }
          
          
          for(int i =0; i < n; i++){
              if(isPal[0][i]) dp[i] = 0;
              else{
                  int minCuts = INT_MAX;
                  for(int j = 0; j < i; j++){
                      if(isPal[j+1][i]) minCuts = min(minCuts, dp[j]+1);
                  }
                  dp[i] = minCuts;
              }
             
          }
          return dp[n-1];
      }
  };