class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int j = 0, count = k;
        for(int i = 1; i <= k + arr.size(); i++){
            if(j < arr.size() && i == arr[j]) j++;
            else{
                count--;
                if(count == 0) return i;
            }
        }
        return -1;
    }
};