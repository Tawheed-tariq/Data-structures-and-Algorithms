class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int, int> mp;
        for(int i = 0; i < numbers.size(); i++){
            mp[numbers[i]] = i;
        }

        for(int i = 0; i < numbers.size(); i++){
            if(mp[target - numbers[i]] > i)
                return {i+1, mp[target - numbers[i]] + 1};
        }

        return {};
    }
};