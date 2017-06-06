public class Solution {
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        
        int m = obstacleGrid.length;
        int n = obstacleGrid[0].length;
        
        if(m == 0 || n == 0) return 0;
        
        int[][] ret = new int[m][n];
        
        for(int i = 0; i < n; i++) {
            if(obstacleGrid[0][i] == 1) {
                while(i < n) {
                    ret[0][i] = 0;
                    i++;
                }
                break;
            }
            else ret[0][i] = 1;
        }
        for(int i = 0; i < m; i++) {
             if(obstacleGrid[i][0] == 1) {
                while(i < m) {
                    ret[i][0] = 0;
                    i++;
                }
                break;
            }
            else ret[i][0] = 1;
        }
        
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                if(obstacleGrid[i][j] == 1) ret[i][j] = 0;
                else ret[i][j] = ret[i][j - 1] + ret[i - 1][j];
            }
        }
        
        return ret[m-1][n-1];
    }
}