class Solution {
    public:
        string getPermutation(int n, int k) {
            vector<int> nums;
            int fact = 1;
            for(int i = 1; i < n; i++){
                fact *= i;
                nums.push_back(i);
            }
            nums.push_back(n);
            string ans = "";
            k = k-1;
            while(true){
                ans += to_string(nums[k/fact]); //we have to go into k/fact th block
                nums.erase(nums.begin() + k/fact);
                if(nums.size() == 0)
                    break;
                k = k % fact; //in the k/fact block we need k % fact sequence
                fact = fact/nums.size();
            }
            return ans;
        }
    };