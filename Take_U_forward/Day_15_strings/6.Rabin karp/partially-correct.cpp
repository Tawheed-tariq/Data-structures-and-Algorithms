class Solution {
    public:
        int algo(string a, string b){
            int i =0, j = 0;
            while(i < a.size() && b[0] != a[i])
                i++;
            while(j < b.size() && i < a.size() && a[i] == b[j])
                i++, j++;
            if(j == b.size())
                return 1;
            return -1;
        }
    
        int repeatedStringMatch(string a, string b) {
            if(a == b) return 1;
            int count = 1;
            string source = a;
            while(source.size() < b.size()){
                count++;
                source += a;
            }
            if(source == b) return count;
    
            if(algo(source, b) != -1) return count;
            if(algo(source + a, b) != -1) return count+1;
            return -1;
        }
    };