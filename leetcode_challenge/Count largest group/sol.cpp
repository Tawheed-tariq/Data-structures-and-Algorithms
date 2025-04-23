class Solution {
    public:
        int digitSum(int x){
            int sum = 0;
            while(x>0){
                int digit = x%10;
                sum+=digit;
                x /= 10;
            }
            return sum;
        }
        int countLargestGroup(int n) {
            unordered_map<int, int> mp;
            int max_val = 0, count = 0;
            for(int i = 1; i <= n; i++){
                int s = digitSum(i);
                mp[s]++;
                max_val  = max(max_val, mp[s]);
            }
            cout << max_val;
            for(auto ele:mp){
                if(ele.second == max_val)
                    count++;
            }
            return count;
        }
    };