class Solution {
public:
    int findMax(vector<int>& nums){
        int maxi = INT_MIN;
        for(int &ele: nums){
            maxi = max(maxi, ele);
        }
        return maxi;
    }
    int findSum(vector<int>& nums, int mid){
        int sum = 0;
        for(int &ele: nums){
            sum += ceil((float)((float)ele/(float)mid));
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int s = 1, e = findMax(nums);
        while(s < e){
            int mid = s + (e-s)/2;
            if(findSum(nums, mid) <= threshold){
                e = mid;
            }else{
                s = mid + 1;
            }
        }
        return s;
    }
};