int Solution::solve(vector<int> &A, int B) {
    int count = 0;
    int xr = 0;
    map<int, int> mp;
    mp[xr]++;
    for(int i = 0; i < A.size(); i++){
        // prefix XOR till index i:
        xr = xr ^ A[i];
        
        //By formula: x = xr^B:
        int x = xr ^ B;
        
        // add the occurrence of xr^k
        // to the count:
        count += mp[x];
        
        // Insert the prefix xor till index i
        // into the map:
        mp[xr]++;
    }
    return count;
}
