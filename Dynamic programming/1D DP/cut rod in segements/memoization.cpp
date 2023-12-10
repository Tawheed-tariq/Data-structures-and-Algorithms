#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int solve(int n, int x, int y ,int z, vector<int> &dp){
	if(n == 0)
		return 0; 
	if(n < 0)
		return INT_MIN;
	if(dp[n] != -1)
		return dp[n];
	int one = solve(n-x, x, y, z, dp)+1;
	int two = solve(n-y, x, y,z,dp)+1;
	int three = solve(n-z, x,y,z,dp)+1;
	dp[n] = max(one,max(two,three));
	return dp[n];
}
int cutSegments(int n, int x, int y, int z) {
	vector<int> dp(n+1, -1);
	int ans = solve(n, x, y, z, dp);
	if(ans < 0)
		return 0;
	return ans;
}