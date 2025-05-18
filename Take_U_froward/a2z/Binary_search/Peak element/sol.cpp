class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int s = 0, e = n - 1;
        while(s <= e){
            int mid = s + (e-s)/2;
            if(mid + 1 < n && nums[mid+1] > nums[mid])
                s = mid +1;
            else if(mid - 1 >= 0 && nums[mid - 1] > nums[mid])
                e = mid-1;
            else 
                return mid;
        }
        return s;
    }
};