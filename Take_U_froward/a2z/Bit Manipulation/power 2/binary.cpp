class Solution {
public:

// Now consider :-
// bit representation of 7  -> 0111
// bit representation of 8  -> 1000
// bitwise AND of 7 and 8 -> 0000
// we are gonna use this property for for all numbers which are powers of two
    bool isPowerOfTwo(int n) {
        if(n<=0) return false;
        return ((n&(n-1))==0);
    }
};