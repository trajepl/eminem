public class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int m = matrix.length;
        if(m == 0) return false;
        int n = matrix[0].length;
        
        int left = 0; 
        int right = m * n - 1;
        
        while(left <= right) {
            int mid = (left + right) / 2;
            int x = mid / n;
            int y = mid - x * n;
            if(matrix[x][y] < target) left = mid + 1;
            else if(matrix[x][y] > target) right = mid - 1;
            else return true;
        }
        return false;
    }
}