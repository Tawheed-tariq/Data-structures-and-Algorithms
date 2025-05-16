class StockSpanner {
    public:
        vector<int> arr;
        StockSpanner() {
            
        }
        
        int next(int price) {
            int size = arr.size();
            int count = 1;
            for(int i = size- 1; i>=0; i--){
                if(price >= arr[i])
                    count++;
                else
                    break;
            }
            arr.push_back(price);
            return count;
        }
    };
    
    /**
     * Your StockSpanner object will be instantiated and called as such:
     * StockSpanner* obj = new StockSpanner();
     * int param_1 = obj->next(price);
     */