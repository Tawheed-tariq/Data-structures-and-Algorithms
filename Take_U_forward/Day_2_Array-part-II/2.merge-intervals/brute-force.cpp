class Solution {
    public:
        vector<vector<int>> merge(vector<vector<int>>& intervals) {
            vector<vector<int>> ans;
            sort(intervals.begin(), intervals.end());
            vector<int> prev = intervals[0];
    
            for(int i =1; i < intervals.size(); i++){
                vector<int> interval = intervals[i];
                if(interval[0] <= prev[1])
                    prev[1] = max(interval[1], prev[1]);
                else{
                    ans.push_back(prev);
                    prev = interval;
                }
            }
            ans.push_back(prev);
            return ans;
        }
    };