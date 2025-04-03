class Solution {
    public:
    
        vector<int> countBits(int n) {
            vector<int> arr(n+1, 0);
            int sub = 1;
            for(int i = 1; i <= n; i++){
                if(sub * 2 == i) sub = i; //if power of 2 then change sub
    
                arr[i] = arr[i - sub] + 1;
            }
            return arr;
        }
    };