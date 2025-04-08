class Solution {
    public:
        int minimumOperations(vector<int>& nums) {
            unordered_map<int, int> T; //track count of all
            unordered_map<int, int> D; //track duplicates
    
            for(auto num : nums){
                T[num]++;
                if(T[num] > 1)
                    D[num]++;
            }
    
            int ans = 0, i = 0;
            int n = nums.size();
            while(!D.empty()){
                if(n-i < 3){
                    ans++;
                    break;
                }else{
                    int x = i++;
                    int y = i++;
                    int z = i++;
    
                    if(D.count(nums[x]))
                        if(--D[nums[x]] == 0) D.erase(nums[x]);
                    if(D.count(nums[y]))
                        if(--D[nums[y]] == 0) D.erase(nums[y]);
                    if(D.count(nums[z]))
                        if(--D[nums[z]] == 0) D.erase(nums[z]);
                    
                    ans++;
                }
            }
            return ans;
        }
    };