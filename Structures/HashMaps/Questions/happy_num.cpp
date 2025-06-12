class Solution {
public:
    int getNewNum(int n){
        int num  = 0;
        while( n > 0){
            int digit = n%10;
            num += digit*digit;
            n = n / 10;
        }
        return num;
    }
    bool isHappy(int n) {
        unordered_set<int> visits;

        while(visits.find(n) == visits.end()){
            visits.insert(n);
            n = getNewNum(n);
            if(n == 1) return true;
        }
        return false;
    }
};