class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        int count = 0, xori = 0;
        unordered_map<int, int> mp;
        
        for(int i = 0; i < arr.size(); i++){
            xori ^= arr[i];
            
            if(xori == k) count++;
            
            if(mp.find(xori ^ k) != mp.end()){
                count += mp[xori^k];
            }
            
            mp[xori]++;
        }
        return count;
        
    }
};