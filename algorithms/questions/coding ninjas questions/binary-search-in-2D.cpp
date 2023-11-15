bool searchMatrix(int mat[][4],int row, int col, int target) {
        // int row = mat.size();
        // int col = mat[0].size();
        int start = 0, end = row*col-1;
        int mid = start + (end-start)/2;
        while(start <= end){
            int element = mat[mid/col][mid%col];
            if(element == target)
                return 1;
            else if(element < target)
                start = mid +1;
            else if(element > target)
                end = mid -1;
            mid = start + (end-start)/2;
        }
        return 0;
}