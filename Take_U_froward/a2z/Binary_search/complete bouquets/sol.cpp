class Solution {
public:
    void findMinMax(vector<int>& nums, int &mini, int &maxi){
        for(int &ele: nums){
            mini = min(mini, ele);
            maxi = max(maxi, ele);
        }
    }
    bool canComplete(vector<int>& bloomDay, int m, int k, int days){
        int count = 0;
        for(int i = 0; i < bloomDay.size(); i++){
            if(bloomDay[i] <= days)
                count++;
            else
                count = 0;
            
            if(count == k){
                m--;
                count = 0;
            }
            if(m==0) return true;
        }
        return m == 0;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {

        if((long long)m * k > bloomDay.size()) return -1;
        int s = INT_MAX, e = INT_MIN;
        findMinMax(bloomDay, s, e);

        while(s < e){
            int mid = s + (e-s)/2;
            if(canComplete(bloomDay, m,k, mid))
                e = mid;
            else
                s = mid+1;
        }
        return s;
    }
};