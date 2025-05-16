struct Jobs{
    int id;
    int profit;
    int dead;
};

class Solution {
  public:
    bool static comparator(struct Jobs j1, struct Jobs j2){
        if(j1.profit > j2.profit)
            return true;
        return false;
    }
    int findMax(vector<int> arr){
        int maxi = INT_MIN;
        for(int i = 0; i < arr.size(); i++){
            maxi = max(arr[i], maxi);
        }
        return maxi;
    }
    vector<int> JobSequencing(vector<int> &id, vector<int> &deadline,
                              vector<int> &profit) {
        int size = findMax(deadline), n = id.size();
        struct Jobs jobs[n];
        for(int i =0; i < n; i++){
            jobs[i].id = id[i], jobs[i].profit = profit[i], jobs[i].dead = deadline[i];
        }
        
        sort(jobs, jobs + n, comparator);
        unordered_map<int, bool> mp;
        int prof = 0, count =0;
        for(int i = size-1; i >= 0; i--){
            for(int j = 0; j < n; j++){
                if(jobs[j].dead > i){
                    if(mp.find(j) == mp.end()){
                        prof += jobs[j].profit;
                        mp[j] = true;
                        count++;
                        break;
                    }
                }
            }
        }
        return {count, prof};
    }
};