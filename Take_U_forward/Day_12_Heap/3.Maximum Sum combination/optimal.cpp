vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C) {
    vector<int> ans(C);
    int ind = 0;
    priority_queue<pair<int, pair<int,int>>> maxHeap;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    reverse(A.begin(), A.end());
    reverse(B.begin(), B.end());
    
    set<pair<int,int>>vis;
    
    maxHeap.push({A[0]+B[0], {0,0}});
    
    while(!maxHeap.empty() && ind < C){
        pair<int, pair<int,int>> ele = maxHeap.top();
        maxHeap.pop();
        
        int sum = ele.first;
        int i = ele.second.first, j = ele.second.second;
        
        ans[ind] = sum;
        
        if(i+1 < A.size()){
            if(vis.find({i+1, j}) == vis.end()){
                maxHeap.push({A[i+1]+B[j], {i+1, j}});
                vis.insert({i+1, j});
            }
        }
        
        if(j+1 < A.size()){
            if(vis.find({i, j+1}) == vis.end()){
                maxHeap.push({A[i]+B[j+1], {i, j+1}});
                vis.insert({i, j+1});
            }
        }
        ind++;
        
    }
    return ans;
        
}
