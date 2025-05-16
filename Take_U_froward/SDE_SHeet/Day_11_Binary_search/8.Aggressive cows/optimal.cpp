bool canWePlace(vector<int> &stalls, int dist, int cows){
    int n = stalls.size(), cnt = 1, last = stalls[0]; //first cow is placed at first stall
    for(int i = 1; i < n; i++){
        if(stalls[i] - last >= dist){
            cnt++;
            last = stalls[i];
        }
        if(cnt >= cows) return true;
    }
    return false;
}
int aggressiveCows(vector<int> &stalls, int k)
{
    sort(stalls.begin(), stalls.end());
    int n =stalls.size(), low = 1, high = stalls[n-1] - stalls[0];

    while(low <= high){
        int mid = low + (high - low)/2;
        if(canWePlace(stalls, mid, k))
            low = mid+1;
        else
            high = mid - 1;

    }
    return high;
}