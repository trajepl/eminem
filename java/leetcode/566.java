public class Solution {
    public int[][] matrixReshape(int[][] nums, int r, int c) {
        int row = nums.length, col = nums[0].length;
        if(row * col != r * c) return nums;
        
        int[][] ret = new int[r][c];
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                int pos = col * i + j;
                int row_ = pos / c;
                int col_ = pos % c;
                // System.out.println(pos + ": " + row_ + "," + col_);
                ret[row_][col_] = nums[i][j];
            }
        }
        return ret;
    }
}
