class Solution {
    public:
        bool check(vector<int> arr){
            for(int i = 0; i < arr.size(); i++){
                for(int j = i+1; j < arr.size(); j++){
                    if(arr[i] % arr[j] != 0 && arr[j] % arr[i] != 0)
                        return false;
                }
            }
            return true;
        }
        void solve(vector<int> nums, vector<int> &output, int ind, vector<int> &ans, int &len){
            if(ind >= nums.size()){
                if(check(output) && output.size() > len){
                    len = output.size();
                    ans = output;
                }
                return;
            }
            solve(nums, output, ind+1, ans, len);
            output.push_back(nums[ind]);
            solve(nums, output, ind+1, ans, len);
            output.pop_back();
        }
        vector<int> largestDivisibleSubset(vector<int>& nums) {
            vector<int> ans;
            vector<int> out;
            int len = 0;
            solve(nums, out, 0, ans, len);
            return ans;
        }
    };