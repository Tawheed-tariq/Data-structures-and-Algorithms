class Solution {

    public:
      int coin(vector<int> &coins, int sum, vector<int> &dp){
          if(sum == 0) return 0;
          if(sum < 0) return INT_MAX;
          if(dp[sum] != -1) return dp[sum];
          
          int result = INT_MAX;
          for(int i =0; i < coins.size(); i++){
              if(coins[i] > 0){
                  int sub_res = coin(coins, sum - coins[i], dp);
                  if(sub_res != INT_MAX && sub_res + 1 < result){
                    //If we have found a valid way to form sum - coins[i], we add 1 (because we are using one more coin coins[i] to reach sum).
                    // We compare this value (sub_res + 1) with the current result.
                    // If sub_res + 1 is smaller, we update result to store the minimum number of coins required.
                      result = sub_res + 1;
                  }   
              }
          }
          
          dp[sum] = result;
          return result;
      }
      int minCoins(vector<int> &coins, int sum) {
          vector<int> dp(sum+1, -1);
          int result = coin(coins, sum, dp);
          return result == INT_MAX? -1: result;
      }
  };