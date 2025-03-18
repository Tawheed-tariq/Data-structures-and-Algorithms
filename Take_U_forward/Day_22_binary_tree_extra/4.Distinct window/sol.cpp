int d_elements(vector<int> ans, int strt, int end){
    unordered_map<int, bool> mp;
    int count = 0;
    for(int i = strt ; i <= end; i++){
        if(!mp[ans[i]]){
            mp[ans[i]] = true;
            count++;
        }
    }
    return count;
}

vector<int> Solution::dNums(vector<int> &A, int B) {
    vector<int> ans;
    int n = A.size();
    if(B > n) return ans;
    
    for(int i = 0; i <= n - B; i++){
        ans.push_back(d_elements(A, i, B+i-1));
    }
    return ans;
}
