class Solution {
    public:
        int solve(vector<vector<int>>& questions, int ind, int &maxi){
            if(ind >= questions.size()){
                return maxi;
            }
            int noPick = solve(questions, ind+1, maxi);
            maxi = maxi + questions[ind][0];
            int pick = solve(questions, ind+questions[ind][1] + 1, maxi);
            maxi = maxi - questions[ind][0];
            return max(pick, noPick);
        }
        long long mostPoints(vector<vector<int>>& questions) {
            int max = 0;
            return solve(questions, 0, max);
        }
    };