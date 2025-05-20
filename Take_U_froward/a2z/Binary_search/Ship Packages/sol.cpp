class Solution {
public:
    int findMax(vector<int>& weights){
        int maxi = INT_MIN;
        for(int &ele: weights){
            maxi = max(maxi, ele);
        }
        return maxi;
    }
    bool possible(vector<int>& weights,int capacity, int days){
        int sum = 0, count = 0;
        for(int & ele: weights){
            if(sum + ele <= capacity)
                sum += ele;
            else{
                sum = ele;
                count++;
            }
        }
        if(sum != 0)
            count++;
        return count <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int s = findMax(weights), e = accumulate(weights.begin(), weights.end(), 0);
        while(s < e){
            int mid = s + (e-s)/2;
            if(possible(weights, mid, days))
                e = mid;
            else
                s = mid+1;
        }
        return s;
    }
};