#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
long long int solve(int n){
    vector<long long int> dp(n+1, -1);
    dp[2] = 1;
    dp[1] = 0;
    dp[0] = 0;
    for(int i = 3; i <= n; i++){
        dp[i] = ((i-1)%MOD)*((dp[i-2]%MOD) + (dp[i-1]%MOD))%MOD;
    }
    return dp[n];
}
long long int countDerangements(int n) {
    return solve(n);
}