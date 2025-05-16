struct Jobs{
    int id;
    int profit;
    int dead;
};

class Solution {
  public:
    
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        int size = *max_element(deadline.begin(), deadline.end()), n = profit.size();
        vector<Jobs> jobs(n);
        for(int i =0; i < n; i++){
            jobs[i] = {i, profit[i], deadline[i]};
        }
        
        sort(jobs.begin(), jobs.end(), [](Jobs &j1, Jobs &j2) {
            return j1.profit > j2.profit;
        });
        vector<int> slot(size+1, -1);

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