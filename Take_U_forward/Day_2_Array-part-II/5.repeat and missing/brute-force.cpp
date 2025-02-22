vector<int> Solution::repeatedNumber(const vector<int> &A) {
    int n = A.size();
    int mp[n + 1] = {0};
    int repeated = -1, missing = -1;
    for(int i = 0; i < n; i++){
        mp[A[i]]++;
    }
    
    for(int i = 1; i <= n;i++){
        if(mp[i] == 0)
            missing = i;
        else if(mp[i] == 2)
            repeated = i;
        if (repeated != -1 && missing != -1)
            break;
    }
    
    return {repeated, missing};
}