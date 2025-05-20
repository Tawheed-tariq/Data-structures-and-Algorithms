class Solution {
public:
    int findMax(vector<int>& nums){
        int maxi = INT_MIN;
        for(int &ele: nums){
            maxi = max(maxi, ele);
        }
        return maxi;
    }
    bool possible(vector<int>& nums,int subarray_sum, int k){
        int sum = 0, count = 0;
        for(int & ele: nums){
            if(sum + ele <= subarray_sum)
                sum += ele;
            else{
                sum = ele;
                count++;
            }
        }
        if(sum != 0)
            count++;
        return count <= k;
    }
    int splitArray(vector<int>& nums, int k) {
        int s = findMax(nums), e = accumulate(nums.begin(), nums.end(), 0);

        while(s <e){
            int mid = s + (e-s)/2;
            if(possible(nums, mid, k))
                e = mid;
            else 
                s = mid + 1;
        }
        return s;
    }
};