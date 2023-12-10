#include<iostream>
using namespace std;
int findDuplicate(int *, int);
int main(){
    int n =5, arr[n] = {5, 2,2, 3,4}, duplicate;
    duplicate = findDuplicate(arr, n);
    cout << duplicate;

}
int findDuplicate(int arr[], int n){
	for(int i = 0; i< n; i++){
        for(int j = i+1; j<n; j++){
            if(arr[i] == arr[j]){
                return *(arr+j);}
        }
    }
    return -1;
}
