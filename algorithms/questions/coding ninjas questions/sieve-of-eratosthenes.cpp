#include<iostream>
#include<vector>
using namespace std;
void primeNumbersTillN(int N) 
{ 
 	vector<bool> prime(N+1, 1);
	prime[0] = prime[1] = 0;
	for(int i = 2; i*i <= N; i++){//reduced time complexity 
		if(prime[i]){
			for(int j = i*i; j <= N; j = j+i){
				prime[j] = 0;
			}
		}
	}
	for(int i = 2; i<N+1; i++){
		if(prime[i])
			cout << i <<"\t";
	}
}
int main(){
    primeNumbersTillN(40);
}