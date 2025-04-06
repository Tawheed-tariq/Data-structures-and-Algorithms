class Solution {
    public:
        vector<int> largestDivisibleSubset(vector<int>& nums) {
            sort(nums.begin(), nums.end());
    
            vector<int> dp(nums.size(), 1); //length of largest subset ending at nums[i]
            vector<int> prev(nums.size(), -1);
            int maxInd = 0;
    
            for(int i = 1; i < nums.size(); i++){
                for(int j = 0; j < i; j++){
                    if(nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]){
                        dp[i] = dp[j] + 1;
                        prev[i] = j;
                    }
                }
                if(dp[i] > dp[maxInd]){
                    maxInd= i;
                }
            }
    
            vector<int> ans;
            for(int i = maxInd; i >= 0; i = prev[i]){
                ans.push_back(nums[i]);
            }
            return ans;
        }
    };