#include<iostream>
using namespace std;

void spiralPrint(int **input, int nRows, int nCols)
{
    //Write your code here
    int s_row = 0, s_col = 0, e_row = nRows-1, e_col = nCols -1;
    int count = 0, total = nRows*nCols;
    while(count < total){
    for(int i = s_col;count < total && i <= e_col; i++){
        cout << input[s_row][i] << " ";
        count++;
    }
    s_row++;
    for(int i = s_row;count < total && i <= e_row; i++){
        cout << input[i][e_col] << " ";
        count++;
    }
    e_col--;
    for(int i = e_col;count < total && i >= s_col; i--){
        cout << input[e_row][i] << " ";
        count++;
    }
    e_row--;
    for (int i = e_row;count < total && i >= s_row; i--) {
        cout << input[i][s_col] << " ";
        count++;
    }
    s_col++;
    }
}