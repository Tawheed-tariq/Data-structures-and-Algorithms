class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int s = 0, e = nums.size() -1, mid;
        int found = -1, last = -1;
        while(s <= e){
            mid = s + (e-s)/2;
            if(nums[mid] == target){
                found = mid;
                break;
            }
            else if(nums[mid] < target)
                s = mid +1;
            else 
                e = mid -1;
        }

        if(found == -1) return {-1, -1};

        s = found, e = found;
        while(s > 0 && nums[s-1] == target)
            s--;
        while(e < nums.size()-1 && nums[e+1] == target)
            e++;
        return {s, e};
    }
};