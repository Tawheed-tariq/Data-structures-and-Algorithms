class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int , int> mp;

        for(int &ele: nums){
            mp[ele]++;
        }

        for(auto &pair: mp){
            if(pair.second == 1)
                return pair.first;
        }
        return 0;
    }
};