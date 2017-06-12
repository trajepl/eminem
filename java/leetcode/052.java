public class Solution {
    public int totalNQueens(int n) {
        int res = helper(n, 0, new int[n], 0);
        return res;
    }

    private int helper(int n, int row, int[] idxQueue, int res) {
        if(row == n) res++;
        else {
            for(int i = 0; i < n; i++) {
                idxQueue[row] = i;
                if(check(row, idxQueue))
                    res = helper(n, row+1, idxQueue, res);
            }
        }
        return res;
    }

    private boolean check(int row, int[] idxQueue) {
        for(int i = 0; i < row; i++) {
            if(idxQueue[i] == idxQueue[row] || Math.abs(idxQueue[i] - idxQueue[row]) == row - i)
                return false;
        }
        return true;
    }
}
