class Solution {
    public:
        int repeatedStringMatch(string a, string b) {
            // if a == b >>> 1
            // b = prefix + n*a + suffix >>> n+2
            // b = prefix + n*a || n*a + suffix >>> n+1
            // b = n*a >>> n
    
    
    
            if(a == b) return 1;
            int count = 1;
            string source = a;
            while(source.size() < b.size()){
                count++;
                source += a;
            }
            if(source.find(b) != std::string::npos) return count;
            source += a;
            if(source.find(b) != std::string::npos) return count+1;
    
            source += a;
            if(source.find(b) != std::string::npos) return count+2;
            return -1;
        }
    };