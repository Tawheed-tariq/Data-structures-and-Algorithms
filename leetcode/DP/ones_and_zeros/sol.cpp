class Solution {
public:
    int dp[601][101][101]; 
    int solve(vector<string>& strs, int m, int n, int countOnes, int countZeros, int ind){
        if(ind >= strs.size()) return 0;

        if(countOnes > n || countZeros > m) return 0;

        if(dp[ind][countOnes][countZeros] != -1) return dp[ind][countOnes][countZeros];

        string str = strs[ind];
        int ones = count(str.begin(), str.end(), '1');
        int zeros = count(str.begin(), str.end(), '0');

        int ans1 = 0, ans2 = 0, ansWithout = 0;

        if(countOnes + ones <= n && countZeros + zeros <= m){
            ans1 = 1 + solve(strs, m, n, countOnes +ones, countZeros + zeros, ind+1);

            ans2 = solve(strs, m, n, countOnes, countZeros, ind+1);
        }else{
            ansWithout = solve(strs, m, n, countOnes, countZeros, ind+1);
        }

        return dp[ind][countOnes][countZeros] = max({ans1, ans2, ansWithout});
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        memset(dp, -1, sizeof(dp));
        return solve(strs, m, n, 0, 0, 0);
    }
};