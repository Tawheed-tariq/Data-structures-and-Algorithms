class Solution {
    public:
        int linearSearch(vector<int> &nums, int target){
            for(int i = 0; i < nums.size(); i++){
                if(nums[i] == target)
                    return i;
            }
            return -1;
        }
        vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
            vector<int> res;
            for(int i = 0; i < nums1.size(); i++){
                int ind = linearSearch(nums2, nums1[i]);
                int ele = -1;
                for(int j = ind+1; j < nums2.size(); j++){
                    if(nums2[j] > nums2[ind]){
                        ele = nums2[j];
                        break;
                    }
                }
                res.push_back(ele);
            }
            return res;
        }
    };