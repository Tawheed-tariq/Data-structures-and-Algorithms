class Solution {
    public:
        int climbStairs(int n) {
            int one = 1; //do nothing hence one way
            int two = 1; //take one step hence one way
    
            for(int i = 2; i <= n; i++){
                int curr = one + two;
                one = two;
                two = curr;
            }
            return two;
        }
    };