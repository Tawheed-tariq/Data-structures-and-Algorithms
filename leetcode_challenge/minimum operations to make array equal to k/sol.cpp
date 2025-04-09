class Solution {
public:
    int valid(vector<int> nums, int n, int k){
        int maxEle = nums[n-1];
        if(maxEle == k)
            return 0;
        int h = 0;
        for(int i = n-2; i >= 0; i--){
            if(nums[i] != maxEle){
                h = i+1;
                break;
            }
        }
        return h;
    }
    int minOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        if(nums[0] < k)
            return -1;
        int n = nums.size();
        int count = 0;
        while(n > 0){
            n = valid(nums, n, k);
            if(n != 0)
                count++;
            else{
                if(nums[0] != k)
                    count++;
            }
        }
        return count;
    }
};
