// https://www.youtube.com/watch?v=z0cdra6jHs4
class Solution {
    public:
        int numberOfArrays(vector<int>& differences, int lower, int upper) {
            long long min_val = 0, max_val = 0;
            long long curr = 0;
            for(int &ele:differences){
                curr += ele;
                min_val = min(min_val, curr);
                max_val = max(max_val, curr);
            }
            int count  = (upper-lower) - (max_val - min_val) + 1;
            return count> 0 ? count : 0;
        }
    };