public class Solution {
    public int numIslands(char[][] grid) {
        int col = grid.length;
        if(col == 0) return 0;
        int row = grid[0].length;
        
        int cnt = 0;
        
        for(int i = 0; i < col; i++) {
            for(int j = 0; j < row; j++) {
                if(grid[i][j] == '1') {
                    helper(grid, i, j);
                    cnt++;
                }
            }
        }
        
        return cnt;
    }
    
    public void helper(char[][] grid, int i, int j) {
        if(i < 0 || i >= grid.length || j < 0 || j >= grid[0].length || grid[i][j] == '0') return ;
        
        grid[i][j] = '0';
        helper(grid, i+1, j);
        helper(grid, i-1, j);
        helper(grid, i, j+1);
        helper(grid, i, j-1);
    }
}
