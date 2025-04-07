class Solution {
    public:
        void solve(vector<vector<int>>& questions, int ind, int &max, long long &realMax){
            if(ind >= questions.size()){
                if(max > realMax) realMax = max;
                return;
            }
            solve(questions, ind+1, max, realMax);
            max = max + questions[ind][0];
            solve(questions, ind+questions[ind][1] + 1, max , realMax);
            max = max - questions[ind][0];
        }
        long long mostPoints(vector<vector<int>>& questions) {
            int max = 0;
            long long realMax = 0;
            solve(questions, 0, max, realMax);
            return realMax;
        }
    };