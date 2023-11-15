#include<iostream>
#include<array>
using namespace std;
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void reverseArray(int *arr, int m)
{
	// Write your code here.
	int n = 6;
    cout << n << "\n";
	for(int i = m+1,j=n-1; i <= j; i++, j--){
		swap((arr+i), (arr+j));
	}
}

int main(){
    int arr[6] = {1,2,3,4,5,6};
    reverseArray(arr,3);
    for(int i = 0; i<6; i++){
        cout << arr[i] << "\t";
    }
}