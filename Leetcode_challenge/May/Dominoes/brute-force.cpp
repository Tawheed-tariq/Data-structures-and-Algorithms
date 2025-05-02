class Solution {
    public:
        string pushDominoes(string dominoes) {
            const int n = dominoes.size();
            vector<int> L(n);
    
            //calculate the force each domino exerts on left size of it
            int F = 0;
            for(int i = n-1; i >= 0; i--){
                const char c = dominoes[i];
                switch(c){
                    case 'L': F = n; break;
                    case 'R': F = 0; break;
                    case '.': F -= (F>0);
                }
                L[i] = F;
            }
    
            //calculate force each domino applies on right side, and if its force is greater than the force on left side replace . with R otherwise with L
            F = 0;
            for(int i = 0; i < n; i++){
                char &c = dominoes[i];
                switch(c){
                    case 'L': F = 0; break;
                    case 'R': F = n; break;
                    case '.': 
                        F -= (F>0);
                        if(F > L[i]) c = 'R';
                        else if(F < L[i]) c= 'L';
                }
            }
            return dominoes;
        }
    };