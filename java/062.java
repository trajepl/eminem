public class Solution {
    public int uniquePaths(int m, int n) {
        if(m == 0 || n == 0) return 0;
        
        int[][] ret = new int[m][n];
        
        for(int i = 0; i < n; i++) ret[0][i] = 1;
        for(int i = 0; i < m; i++) ret[i][0] = 1;
        
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                ret[i][j] = ret[i][j - 1] + ret[i - 1][j];
            }
        }
            
        return ret[m - 1][n - 1];
    }
}