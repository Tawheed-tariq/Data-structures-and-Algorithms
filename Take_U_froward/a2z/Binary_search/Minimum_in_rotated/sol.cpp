class Solution {
public:
    int findMin(vector<int>& nums) {
        int s = 0, e = nums.size()-1, pivot = nums[0];

        while(s <= e){
            int mid = s + (e-s)/2;
            if(nums[mid] >= pivot)
                s = mid + 1;
            else
                e = mid - 1;
        }
        if(s >= nums.size()) return pivot;
        return nums[s];
    }
};