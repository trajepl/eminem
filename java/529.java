public class Solution {
    public char[][] updateBoard(char[][] board, int[] click) {
        int i = click[0], j = click[1];
        if(board[i][j] == 'M') {
            board[i][j] = 'X'; 
            return board;
        }
        board = paintBoard(board, i, j);
        return board;
    }
    
    public char[][] paintBoard(char[][] board, int i, int j) {
        for(int m = i - 1; m < i + 2; m++) {
            if(m < 0 || m >= board.length) continue;
            for(int n = j - 1; n < j + 2; n++) {
                if(n < 0 || n >= board[0].length) continue;
                if(m==i && n==j) continue;
                int numM = numMine(m, n, board);
                if(numM == 0) {
                    board[m][n] = 'B';
                    board = paintBoard(board, m, n);    
                } else {
                    if(board[m][n] == 'M') {
                        continue;
                    }
                    board[m][n] = (char)(numM+'0');
                }
            }
        }
        return board;
    }
    
    public int numMine(int i, int j, char[][] board) {
        int ret = 0;
        for(int m = i - 1; m < i + 2; m++) {
            if(m < 0 || m >= board.length) continue;
            for(int n = j - 1; n < j + 2; n++) {
                if(n < 0 || n >= board[0].length) continue;
                if(board[m][n] == 'M') ret += 1;
            }
        }
        return ret;
    }

    public static void main(String[] args) {
        s = new Solution();
        char[][] ret = s.updateBoard(new char[][]{"EEEEE","EEMEE","EEEEE","EEEEE"}, new int[]{3,0});
    }
}
