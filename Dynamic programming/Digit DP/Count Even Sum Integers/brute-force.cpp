class Solution {
    public:
        int sumDigits(int num){
            int sum = 0;
            while(num > 0){
                int digit = num%10;
                sum += digit;
                num /= 10;
            }
            return sum;
        }
        int countEven(int num) {
            int count = 0;
            for(int i = 1; i <= num; i++){
                int sum = sumDigits(i);
                if(sum % 2 == 0) count++;
            }
            return count;
        }
    };