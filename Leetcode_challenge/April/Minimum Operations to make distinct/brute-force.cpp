class Solution {
    public:
        bool isDistinct(vector<int> arr, int s){
            unordered_map<int, bool> mp;
            for(int i =s; i < arr.size(); i++){
                if(mp[arr[i]] == true)
                    return false;
                mp[arr[i]] = true;
            }
            return true;
        }
        int minimumOperations(vector<int>& nums) {
            int s = 0;
            while(s < nums.size()){
                if(isDistinct(nums, s))
                    break;
                else
                    s += 3;
            }
            return s/3;
        }
    };