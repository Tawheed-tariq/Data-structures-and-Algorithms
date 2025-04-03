class Solution {
    public:
        int findOnes(int n){
            int cnt = 0;
            while(n > 0){
                if(n %2 == 1) cnt++;
                n = n/2;
            }
            return cnt;
        }
        vector<int> countBits(int n) {
            vector<int> arr;
            for(int i = 0; i <= n; i++){
                arr.push_back(findOnes(i));
            }
            return arr;
        }
    };