#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
long long int solve(int n){
    long long int prev1 = 1;
    long long int prev2 = 0;
    for(int i = 3; i <= n; i++){
        long long int curr = ((i-1)%MOD)*((prev2%MOD) + (prev1%MOD))%MOD;
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}
long long int countDerangements(int n) {
    return solve(n);
}