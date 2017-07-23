public class Solution {
    public int maximalSquare(char[][] matrix) {
        if(matrix == null || matrix.length == 0 || matrix[0].length == 0) return 0;
        int m = matrix.length, n = matrix[0].length, ret = 0;
        
        int[] heights = new int[n];
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                heights[j] = (matrix[i][j] == '0') ? 0 : heights[j]+1;
            }
            
            for(int j = 0; j < n; j++) {
                if(heights[j] == 0) continue;
                
                int left = j, right = j;
                while(left >= 0 && heights[left] >= heights[j]) left--;
                left++;
                while(right < n && heights[right] >= heights[j]) right++;
                right--;
                
                int width = right - left + 1;
                int factor = Math.min(width, heights[j]);
                ret = Math.max(ret, factor*factor);
            }
        }
        return ret;
    }

    public int maximalSquare(char[][] a) {
 		if(a.length == 0) return 0;
	    int m = a.length, n = a[0].length, result = 0;
	    int[][] b = new int[m+1][n+1];

	    for (int i = 1 ; i <= m; i++) {
    	    for (int j = 1; j <= n; j++) {
        	    if(a[i-1][j-1] == '1') {
            	    b[i][j] = Math.min(Math.min(b[i][j-1] , b[i-1][j-1]), b[i-1][j]) + 1;
                	result = Math.max(b[i][j], result); // update result
	            }
    	    }
	    }
	    return result*result;
	}
}

