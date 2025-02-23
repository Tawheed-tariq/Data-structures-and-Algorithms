class Solution {
    public:
        int binarySearch(vector<int>& nums,int s, int e, int target){
            int mid;
            while(s <= e){
                mid = s + (e-s)/2;
                if(nums[mid] == target)
                    return mid;
                else if(nums[mid] < target)
                    s = mid+1;
                else
                    e = mid -1;
            }
            return -1;
        }
        int search(vector<int>& nums, int target) {
            int s= 0, e = nums.size() -1;
            int pivot = nums[0], mid;
    
            while(s <= e){
                mid = s + (e-s)/2;
                if(nums[mid] >= pivot)
                    s = mid + 1;
                else
                    e = mid - 1;
            }
            int ans1 = binarySearch(nums, 0, s-1, target);
            int ans2 = binarySearch(nums, s, nums.size()-1, target);
            return max(ans1, ans2);
        }
    };