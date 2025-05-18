class Solution {
public:
    int hoursToEatAll(vector<int>& piles, int k){
        int hours = 0;
        for(int &ele: piles){
            hours += ele/k;
            if(ele % k != 0)
                hours++;
        }
        return hours;
    }
    int findMax(vector<int>& piles){
        int maxi = INT_MIN;
        for(int &ele: piles){
            maxi = max(maxi, ele);
        }
        return maxi;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int e = findMax(piles);
        int s = 1;

        while(s < e){
            int mid = s+ (e-s)/2;
            int hours = hoursToEatAll(piles, mid);
            if(hours <= h)
                e = mid;
            else 
                s = mid+ 1;
        }
        return e;
    }
};