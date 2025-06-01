class Solution {
public:

    vector<int> countBits(int n) {
        vector<int> arr(n+1, 0);
        int sub = 1;
        for(int i = 1; i <= n; i++){
            arr[i] = __builtin_popcount(i);
        }
        return arr;
    }
};