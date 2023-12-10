#include<iostream>
using namespace std;
void wavePrint(int arr[][4], int , int );

int main(){
    int arr[3][4] = {{1,23,4,5}, {3,4,12,7},{67,45,12,34}};
    wavePrint(arr, 3, 4);
}

void wavePrint(int arr[][4], int nRows, int mCols)
{
    for(int i = 0; i< mCols; i++){
        if(i%2 == 0){
            for(int j = 0; j < nRows; j++){
                cout << arr[j][i] << "\t";
            }
        }
        else{
            for(int j = nRows-1; j >= 0; j--){
                cout << arr[j][i] << "\t";
            }
        }
    }
}