class Solution {
    public:
        int solve(int ind, int n){
            if(ind == n) return 1;
            if(ind > n) return 0;
    
            int one = solve(ind+1, n);
            int two = solve(ind+2, n);
            return one + two;
        }
        int climbStairs(int n) {
            return solve(0, n);
        }
    };