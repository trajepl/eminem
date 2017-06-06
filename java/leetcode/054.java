public class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> ret = new ArrayList<>();
        if(matrix.length == 0) return ret;
        
        int rows = matrix.length;
        int cols = matrix[0].length;
        
        int visitedRows = 0;
        int visitedCols = 0;
        
        int[] y = {0, 1, 0, -1};
        int[] x = {1, 0, -1, 0};
        
        int direct = 0;
        int startx = 0, starty = 0;
        
        int candidateNum = 0;
        
        int step = 0;
        
        while(true) {
            if(x[direct] == 0) {
                candidateNum = rows - visitedRows;
            } else {
                candidateNum = cols - visitedCols;
            }
            
            if(candidateNum <= 0) break;
            
            ret.add(matrix[startx][starty]);
            step++;
            
            if(step == candidateNum) {
                step = 0;
                visitedRows += x[direct] == 0 ? 0 : 1;
                visitedCols += y[direct] == 0 ? 0 : 1;
                
                direct++;
                direct = direct % 4;
            }
            startx += y[direct];
            starty += x[direct];
        }
        
        return ret;
    }
}