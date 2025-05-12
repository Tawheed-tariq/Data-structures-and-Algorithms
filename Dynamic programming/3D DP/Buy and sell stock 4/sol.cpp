class Solution {
public:
    vector<vector<vector<int>>> mem;

    int recurssion(vector<int> &prices, int n, int k, int pos, bool brought){
        if(k ==0 || pos >= n) return 0;

        if(mem[brought][k][pos] != -1) return mem[brought][k][pos];

        int skip  = recurssion(prices, n, k, pos+1, brought);

        int sum = 0;
        if(brought){
            sum = max(skip, recurssion(prices, n, k-1, pos+1, !brought)+prices[pos]);
        }else{
            sum = max(skip, recurssion(prices, n, k, pos+1, !brought)-prices[pos]);
        }
        return mem[brought][k][pos] = sum;
         
    }

    int maxProfit(int k, vector<int>& prices) {
        mem.resize(2,vector<vector<int>> (k+1,vector<int> (prices.size(),-1)));     //mem[bought][k][pos]
        return recurssion(prices,prices.size(),k,0,false);
    }
};