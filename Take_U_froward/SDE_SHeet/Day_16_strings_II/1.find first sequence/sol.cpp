class Solution {
public:
    int strStr(string haystack, string needle) {
        int n1 = haystack.size(), n2 = needle.size();
        int i = 0;
        while( i < n1){
            int j = 0;
            while( i < n1 && haystack[i] != needle[0])
                i++;
            while(i< n1 && j < n2 && haystack[i] == needle[j])
                i++, j++;
            if(j == n2) return i-j;
            else i = i-j+1;
        }
        return -1;
    }
};