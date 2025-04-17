class Solution {
    public:
        int countPairs(vector<int>& nums, int k) {
            unordered_map<int, vector<int>> mp;
            for(int i =0; i < nums.size(); i++){
                mp[nums[i]].push_back(i);
            }
    
            int count = 0;
            for(auto x: mp){
                vector<int> list = x.second;
                int n = list.size();
                for(int i =0; i < n; i++){
                    for(int j = i+1; j < n; j++){
                        int idx1 = list[i];
                        int idx2 = list[j];
                        if((idx1*idx2)%k == 0) count++;
                    }
                }
            }
            return count;
        }
    };