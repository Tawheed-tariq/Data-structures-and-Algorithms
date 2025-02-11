class Solution {
    public:
        vector<int> majorityElement(vector<int>& nums) {
            unordered_map<int, int> mp;
            for(int i = 0; i < nums.size(); i++){
                mp[nums[i]] += 1;
            }
    
            vector<int> majority_element;
            int thershold = nums.size()/3;
    
            for(auto x: mp){
                if(x.second > thershold)
                    majority_element.push_back(x.first);
            }
            return majority_element;
        }
    };