class Solution {
public:
    int solve(int x){
        int count = 0;
        while(x != 0){
            if((x & 1) == 1) count++;
            x>>=1;
        }
        return count;
    }
    vector<int> countBits(int n) {
        vector<int> arr(n+1, 0);
        int sub = 1;
        for(int i = 1; i <= n; i++){
            arr[i] = solve(i);
        }
        return arr;
    }
};