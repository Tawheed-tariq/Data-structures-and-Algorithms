struct Item{
    int value;
    int weight;
};


class Solution {
  public:
    bool static compare(struct Item i1, struct Item i2){
        double r1 = (double)i1.value/i1.weight;
        double r2 = (double)i2.value/i2.weight;
        return r1>r2;
    }
    
    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();
        struct Item items[n];
        for(int i = 0; i < n; i++){
            items[i].value = val[i], items[i].weight = wt[i];
        }
        
        sort(items, items + n, compare);
        
        double prof = 0;
        for(int i = 0; i < n; i++){
            if(items[i].weight <= capacity){
                prof += items[i].value;
                capacity -= items[i].weight;
            }else{
                prof += ((double)capacity/items[i].weight)*items[i].value;
                break;
            }
        }
        return prof;
    }
};