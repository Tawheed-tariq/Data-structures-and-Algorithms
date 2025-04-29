class Solution {
    public:
        int numRabbits(vector<int>& answers) {
            unordered_map<int, int> mp;
            int count = 0;
            for(int i = 0; i < answers.size(); i++){
                if(mp[answers[i]] == 0){
                    mp[answers[i]] = answers[i];
                    count += 1+answers[i];
                }else{
                    mp[answers[i]]--;
                }
            }
            return count;
        }
    };