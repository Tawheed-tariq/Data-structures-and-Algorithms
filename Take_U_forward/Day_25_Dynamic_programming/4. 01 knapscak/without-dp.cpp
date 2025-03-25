int solve(vector<int> &values, vector<int> &weights, int n, int m){
	if(n < 0 || m == 0) return 0;

	if(weights[n] > m) return solve(values, weights, n-1, m);
	else{
		int take = values[n] + solve(values, weights, n-1, m-weights[n]);
		int notTake = solve(values, weights, n-1, m);
		return max(take , notTake);
	}
}

int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
	return solve(values, weights, n-1, w);
}