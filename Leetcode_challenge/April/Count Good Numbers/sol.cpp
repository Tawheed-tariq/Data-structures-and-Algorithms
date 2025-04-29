// https://www.youtube.com/watch?v=ZhLyJpBVU1s
class Solution {
    const long long MOD = 1e9 + 7;
    #define ll long long
public:
    ll modPow(ll base, ll exp){
        ll res = 1;
        base %= MOD;
        while(exp >0 ){
            if(exp % 2 == 1)
                res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }
        return res;
    }
    int countGoodNumbers(long long n) {
        ll evens = (n+1)/2;
        ll odds = n/2;

        return (modPow(5, evens) * modPow(4, odds))%MOD;  // 5^evens * 4^odds gives us the number of good integers
    }
};