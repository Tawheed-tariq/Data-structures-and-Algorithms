class Solution {
    public:
        int countLargestGroup(int n) {
            int groups[37] = {}; // digit sum can be at most 9+9+9+9=36 for n <= 9999
            int max_val = 0, count = 0;
            for(int i = 1; i <= n; i++){
                int s = 0, x = i;
                while(x>0){
                    int digit = x%10;
                    s+=digit;
                    x /= 10;
                }
                groups[s]++;
                max_val  = max(max_val, groups[s]);
            }
            for(int &ele:groups){
                if(ele == max_val)
                    count++;
            }
            return count;
        }
    };