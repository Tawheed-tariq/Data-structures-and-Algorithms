class Solution {
    public:
        string countAndSay(int n) {
            if(n == 1)
                return "1";
            if(n == 2)
                return "11";
    
            string str = "11";
    
            for(int i = 3; i <= n; i++){
                string temp = "";
                str = str + "&"; //add a delimiter
                int cnt = 1;
    
                for(int j = 1; j < str.size(); j++){
                    if(str[j] != str[j-1]){
                        temp += to_string(cnt); //add the counter to tmep
                        temp += str[j-1]; //add data of the counter
                        cnt = 1; //reset counter
                    }else
                        cnt++;
                }
                str = temp;
    
            }
    
            return str;
            
    
        }
    };