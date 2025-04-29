// https://www.youtube.com/watch?v=dsHmPTHuIkA
class Solution {
    public:
        #define ll long long
        unordered_set<ll> done;
        vector<ll> fact;
        ll kPermutations = 0;
    
        void computeFacts(int &n){
            fact[0] = 1;
            fact[1] = 1;
    
            for(ll i = 2; i <= 10 ;i++){
                fact[i] = i*fact[i-1];
            }
        }
        ll countAllPermutations(vector<ll> &freq, int n){
            ll count = fact[n];
            for(int i = 0; i <= 9; i++){
                count /= fact[freq[i]];
            }
            return count;
        }
        ll allArrangements(string number, int &n){
            sort(number.begin(), number.end());
            if(done.count(stoll(number)) ) return 0;
    
            done.insert(stoll(number));
    
            vector<ll> freq(10);
            for(auto c: number){
                freq[c-'0']++;
            }
    
            ll totalPerms = countAllPermutations(freq, n);
            ll invalidPerms = 0;
            if(freq[0] > 0){
                freq[0]--;
                invalidPerms = countAllPermutations(freq, n-1);
            }
            return totalPerms - invalidPerms;
        }
        bool isKPalindrome(string & number, int &n, int &k){
            return stoll(number)%k ==0;
        }
        void generatePalindrome(int pos, int &n, string &number, int &k){
            if(pos >= (n+1)/2){
                if(isKPalindrome(number, n, k))
                    kPermutations += allArrangements(number, n);
                return;
            }
    
            char start = pos == 0? '1':'0';
            while(start <= '9'){
                number[pos] = start;
                number[n-pos-1] = start;
                generatePalindrome(pos+1, n , number, k);
                start++;
            }
            number[pos] = ' ';
    
        }
        long long countGoodIntegers(int n, int k) {
            fact = vector<ll>(11);
            computeFacts(n);
            string number(n, ' ');
            generatePalindrome(0, n, number, k);
            return kPermutations;
        }
    };