class Solution {
public:
    int maxDepth(string s) {
        int maxi = 0, count = 0;

        for(char &ch: s){
            if(ch == '(') count++;
            else if(ch == ')'){
                maxi = max(maxi, count);
                count--;
            }
        }
        return maxi;
    }
};