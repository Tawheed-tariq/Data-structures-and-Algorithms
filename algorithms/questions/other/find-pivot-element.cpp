#include<iostream>
using namespace std;
int find_pivot(int *, int);
int main(){
    int n =8, arr[n]= {7,8,9,1,2,3,4,5};
    cout << find_pivot(arr,n);
}

int find_pivot(int arr[], int n){
    int start = 0, end = n-1;
    int mid = start + (end - start)/2;
    while (start<end)
    {
        if(arr[mid]>=arr[0])
            start = mid +1;
        else
            end =mid;
        mid = start + (end -start)/2;
    }
    return start;
}