int solve(vector<int> &values, vector<int> &weights, int n, int m,vector<vector<int>> &dp){
	if(n < 0 || m == 0) return 0;

	if(dp[n][m] != -1) return dp[n][m];
	if(weights[n] > m) dp[n][m] = solve(values, weights, n-1, m, dp);
	else{
		int take = values[n] + solve(values, weights, n-1, m-weights[n], dp);
		int notTake = solve(values, weights, n-1, m, dp);
		dp[n][m] = max(take , notTake);
	}
	return dp[n][m];
}

int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
	vector<vector<int>> dp(n, vector<int>(w+1, -1));
	return solve(values, weights, n-1, w, dp);
}