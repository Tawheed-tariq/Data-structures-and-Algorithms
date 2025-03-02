class Solution {
    public:
        int myAtoi(string s) {
            int  i =0, n = s.size(), res = 0,sign = 1;
            while( i < n && s[i] == ' ')
                i++;
    
    
            if(i < n && s[i] == '+')
                i++;
            else if(i < n && s[i] == '-')
                sign = -1, i++;
    
    
            while(i < n){
                if(0 <= s[i] - '0' && s[i] - '0' <= 9){
                    int digit = s[i] - '0';
                    if(res > INT_MAX/10 || (res == INT_MAX/10 && digit > INT_MAX%10))
                        return sign == 1? INT_MAX : INT_MIN;
                    res = res*10 + digit;
                    i++;
                }else
                    return res*sign;
            }
            return res*sign;
        }
    };