public class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        if(matrix == null | matrix.length == 0 || matrix[0].length == 0) return false;
        
        int col = matrix[0].length, row = matrix.length;
        int l, r;
        int rowCur = 0, colCur = 0;
    
        while(colCur < col || rowCur < row) {
            l = colCur; r = col-1;
            if(rowCur < row) {
                while(l <= r) {
                    int mid = (l + r) / 2;
                    if(matrix[rowCur][mid] == target) return true;
                    if(matrix[rowCur][mid] < target) l = mid + 1;
                    else r = mid - 1;
                }
            }

            l = rowCur; r = row-1;
            if(colCur < col) {
                while(l <= r) {
                    int mid = (l + r) / 2;
                    if(matrix[mid][colCur] == target) return true;
                    if(matrix[mid][colCur] < target) l = mid + 1;
                    else r = mid - 1;
                }
            }

            rowCur++;
            colCur++;
        }
        return false;
    }
}


public class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        if(matrix.length ==0 || matrix == null){
            return false;
        }
        int rowStart = 0;
        int colStart = 0;
        int rowEnd = matrix.length;
        int colEnd = matrix[0].length;

        int i = rowStart;
        int j = colEnd-1;
        while(i<rowEnd && j >= colStart){
            if(matrix[i][j]== target){
                return true;
            }
            if(matrix[i][j]<target){
                i++;
            }else{
                j--;
            }
        }
        return false;

    }
}
