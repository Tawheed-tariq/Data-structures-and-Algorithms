bool findInMatrix(int x, int arr[][4], int row, int col)
{
    //    Write your code here.
    // int row = arr.size(), col = arr[0].size();
    int rowIndex = 0, colIndex = col -1;
    while(rowIndex < row && colIndex >= 0){
        int ele = arr[rowIndex][colIndex];
        if(ele == x)
            return 1;
        else if(ele < x)
            rowIndex++;
        else if(ele > x)
            colIndex--;
    }
    return 0;
}