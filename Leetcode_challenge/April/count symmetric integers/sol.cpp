class Solution {
    public:
        bool check(int num, int n){
            int sum1 = 0, sum2 = 0;
            for(int i = 0; i < n/2; i++){
                int digit = num%10;
                sum1 += digit;
                num = num/10;
            }
            for(int i = n/2; i < n; i++){
                int digit = num%10;
                sum2 += digit;
                num = num/10;
            }
            return sum1 == sum2;
        }
        int countSymmetricIntegers(int low, int high) {
            int count = 0;
            for(int i = low; i <= high; i++){
                string str = to_string(i);
                if(str.size()%2 != 0) continue;
    
                if(check(i, str.size())) count++;
            }
            return count;
        }
    };