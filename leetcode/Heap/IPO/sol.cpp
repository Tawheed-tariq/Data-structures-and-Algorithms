class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<int> pq; //max heap
        vector<pair<int, int>> projects;
        int n = profits.size();
        for(int i = 0; i < n; i++){
            projects.push_back({capital[i], profits[i]});
        }
        sort(projects.begin(), projects.end());
        int i = 0;

        for(int j = 0; j < k; j++){
            while(i < n && projects[i].first <= w){
                pq.push(projects[i].second);
                i++;
            }

            if(pq.empty()) break;

            w += pq.top();
            pq.pop();
        }

        return w;
    }
};