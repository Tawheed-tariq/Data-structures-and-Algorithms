class Solution {
    public:
        vector<int> LPS(string str){
            int pre = 0;
            int suf = 1;
            vector<int> arr(str.size(), 0); //arr[0] is always 0
    
            while(suf < str.size()){
                if(str[suf] == str[pre]){
                    pre++;
                    arr[suf] = pre;
                    suf++;
                }else{
                    if(pre == 0){
                        //we are at first element
                        arr[suf] = 0;
                        suf++;
                    }else{
                        pre = arr[pre-1]; //go to previous matched value
                    }
                }
            }
            return arr;
        }
        int strStr(string haystack, string needle) {
            int n1 = haystack.size(), n2 = needle.size();
            int i = 0, j = 0;
            vector<int> prefix = LPS(needle);
            while( i < n1){
                if(needle[j] == haystack[i]){
                    i++;
                    j++;
                }
    
                if(j == n2) return i-j;
                else if(i < n1 && needle[j] != haystack[i]){
                    if(j == 0) i++;
                    else j = prefix[j - 1];
                }
            }
            return -1;
        }
    };