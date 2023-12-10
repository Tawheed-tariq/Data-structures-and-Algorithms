#include<iostream>
using namespace std;
void sort(int *, int);
void swap(int *, int *);
int  main(){
    int n = 5 , arr[5] = {1, 4,2,6,3};
    sort(arr, n);
    for(int i = 0; i< n; i++){
        cout << arr[i] << "\t";
    }

}

void sort(int arr[], int n){
    for(int i = 0; i< n; i++){
        int min = i;
        for(int j= i +1; j<n ; j++){
            if(arr[min] > arr[j])
                min = j; 
        }
        swap((arr+i), (arr+min));
    }
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}