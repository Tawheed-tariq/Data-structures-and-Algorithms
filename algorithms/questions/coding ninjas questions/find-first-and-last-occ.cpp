#include<iostream>
using namespace std;
int first_occ(int *, int ,int );
int last_occ(int *, int , int);
pair<int, int> firstAndLastPosition(int *, int , int );
int main(){
    int n = 8, arr[8] = {1,2,3,3,3,3,4,5}, key = 3;
    pair<int,int> p = firstAndLastPosition(arr,n,key);
    cout << p.first << "\t" << p.second;
}

int first_occ(int arr[], int n, int key){
    int start = 0 , end = n-1;
    int mid = start +(end -start)/2;
    int ans = -1;
    while(start <= end){
        if(arr[mid] == key){
            ans = mid;
            end = mid -1;
        }
        else if(arr[mid] > key){
            end = mid-1;
        }
        else if(arr[mid] < key){
            start = mid +1;
        }
        mid = start +(end -start)/2;
    }
    return ans;
}

int last_occ(int arr[], int n, int key){
    int start = 0 , end = n-1;
    int mid = start +(end -start)/2;
    int ans = -1;
    while(start <= end){
        if(arr[mid] == key){
            ans = mid;
            start = mid +1;
        }
        else if(arr[mid] > key){
            end = mid-1;
        }
        else if(arr[mid] < key){
            start = mid +1;
        }
        mid = start +(end -start)/2;
    }
    return ans;
}
pair<int, int> firstAndLastPosition(int arr[], int n, int key)
{
    pair<int,int> p;
    p.first = first_occ(arr,n,key);
    p.second = last_occ(arr,n,key);
    return p;
}