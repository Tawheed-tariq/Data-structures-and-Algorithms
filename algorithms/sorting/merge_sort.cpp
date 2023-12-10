#include<iostream>
#include<vector>
using namespace std;
void merge(int *, int , int);
vector<int> mergeArray(int *, int ,int);
void mergeSort(int *, int ,int);
int main(){
    int n =15, arr[15] = {12,2,34,23,56, 78, 3,0,1,43,90,87,65,34,13};
    mergeSort(arr,0,n-1);
    for(int i =0; i < n; i++){
        cout << arr[i] << "\t";
    }

}


void merge(int arr[], int s, int e){
    //divide arr in two parts
    int mid = s + (e-s)/2;
    int len1 = mid - s +1, len2 = e-mid;
    int *first_arr = new int[len1];
    int *second_arr = new int[len2];
    
    
    //add elements in arrays
    int mainArray_index = s;
    for(int i = 0; i < len1; i++){
        first_arr[i] = arr[mainArray_index++];
    }
    for(int i =0; i < len2; i++){
        second_arr[i] = arr[mainArray_index++];
    }

    //merge two sorted arrays
    int index1 = 0, index2 = 0;
    mainArray_index = s;
    while(index1 < len1 && index2 < len2){
        if(first_arr[index1] < second_arr[index2])
            arr[mainArray_index++] = first_arr[index1++];
        else
            arr[mainArray_index++] = second_arr[index2++];
    }
    while(index1 < len1){
        arr[mainArray_index++] = first_arr[index1++];
    }
    while(index2 < len2){
        arr[mainArray_index++] = second_arr[index2++];
    }
    delete []first_arr;
    delete []second_arr;
}

void mergeSort(int arr[], int s, int e){
    if(s >= e)
        return;
    int mid = s + (e-s)/2;
    mergeSort(arr,s,mid);
    mergeSort(arr,mid+1, e);
    mergeArray(arr,s,e);
}
