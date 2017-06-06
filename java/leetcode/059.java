public class Solution {
    public int[][] generateMatrix(int n) {
        if(n == 0) {
            return new int[][]{};
        }
        int[][] ret = new int[n][n];
        
        
        int[] x = {1, 0, -1, 0};
        int[] y = {0, 1, 0, -1};
        
        int visitedRows = 0;
        int visitedCols = 0;
        
        int startx = 0;
        int starty = 0;
        
        int direct = 0;
        
        int candidateNum = 0;
        
        int step = 0;
        
        int i = 1;
        
        while(true) {
            if(x[direct] == 0) {
                candidateNum = n - visitedRows;
            } else {
                candidateNum = n - visitedCols;
            }
            
            if(candidateNum <= 0) break;
        
            ret[startx][starty] = i++;
            step++;
            
            if(step == candidateNum) {
                step = 0;
                visitedRows += x[direct] == 0 ? 0 : 1;
                visitedCols += y[direct] == 0 ? 0 : 1;
                
                direct++;
                direct %= 4;
            }
            startx += y[direct];
            starty += x[direct];
        }
        return ret;
    }
}