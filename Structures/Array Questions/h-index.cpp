class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int low = 0, high = citations.size() -1 ;
        int size = citations.size();
        while(low <= high){
            int mid = low + (high-low)/2;
            if (citations[mid] == citations.size() - mid) {
                return citations[mid];
            }else if(size - mid > citations[mid]){
                low = mid + 1;
            }else{
                high = mid -1;
            }
        }
        return size - low;
    }
};