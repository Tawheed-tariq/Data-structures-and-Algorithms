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
        int slot[size + 1];

        for (int i = 0; i <= size; i++)
            slot[i] = -1;
        int prof = 0, count =0;
        
        for(int i = 0; i < n; i++){
            for(int j = jobs[i].dead; j > 0; j--){
                if(slot[j] == -1){
                    prof += jobs[i].profit;
                    slot[j] = i;
                    count++;
                    break;
                }
            }
        }
        return {count, prof};
    }
};