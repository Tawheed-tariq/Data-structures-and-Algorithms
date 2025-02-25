vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C) {
    vector<int> ans;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int n1 = A.size(), n2 = B.size();
    for(int i =0; i < n1; i++){
        for(int j = 0; j < n2; j++){
            minHeap.push(A[i] + B[j]);
            if(minHeap.size() > C){
                minHeap.pop();
            }
        }
    }
    for(int i = 0; i < C; i++){
        ans.push_back(minHeap.top());
        minHeap.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;    
}
