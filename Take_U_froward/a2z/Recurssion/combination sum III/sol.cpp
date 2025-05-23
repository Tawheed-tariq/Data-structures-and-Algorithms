class Solution {
public:
    void solve(int k, int n, int i, vector<int> &temp, vector<vector<int>> &ans){
        if(temp.size() == k){
            if(n == 0)
                ans.push_back(temp);
            return;
        }
        if(i > 9) return;

        temp.push_back(i);
        solve(k, n-i, i+1, temp, ans);

        temp.pop_back();
        solve(k, n, i+1, temp, ans);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;

        solve(k, n, 1, temp, ans);
        return ans;
    }
};