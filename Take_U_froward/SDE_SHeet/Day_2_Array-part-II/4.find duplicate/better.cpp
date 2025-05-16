class Solution {
    public:
        int findDuplicate(std::vector<int>& nums) {
            int n = nums.size();
            vector<int> hash(n+1, 0);
    
            for(int i =0; i <n; i++){
                if(hash[nums[i]] == 0)
                    hash[nums[i]]++;
                else
                    return nums[i];
            }
            return -1;
        }
    };