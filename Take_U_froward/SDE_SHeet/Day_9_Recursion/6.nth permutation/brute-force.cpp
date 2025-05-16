class Solution {
    public:
        void permHelper(int i, string &s, vector<string> &res){
            if(i == s.size()){
                res.push_back(s);
                return;
            }
    
            for(int j = i; j < s.size(); j++){
                swap(s[i], s[j]);
                permHelper(i+1, s, res);
                swap(s[i], s[j]);
            }
        }
        string getPermutation(int n, int k) {
            string s;
            vector < string > res;
            //create string
            for (int i = 1; i <= n; i++) {
                s.push_back(i + '0');
            }
            permHelper(0, s,res);
            sort(res.begin(), res.end());
    
            auto it = res.begin() + (k-1);
            return *it;
        }
    };