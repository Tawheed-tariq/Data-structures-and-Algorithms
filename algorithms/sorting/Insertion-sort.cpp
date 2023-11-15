#include<iostream>
using namespace std;
void insertion_sort(int *, int);
int main(){
    int n = 5 , arr[5] = {1, 5,2,6,3};
    insertion_sort(arr,n);
    for(int i = 0; i< n; i++){
        cout << arr[i] << "\t";
    }
}

void insertion_sort(int arr[], int n){
    for(int i = 1; i<n; i++){
        int temp = arr[i], j = i-1;
        while(j>=0){
            //shift
            if(temp < arr[j])
                arr[j+1] = arr[j];
            else
                break;
            j--;
        }
        arr[j+1] = temp;
    }
}