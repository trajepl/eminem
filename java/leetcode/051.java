import java.util.*;

public class Solution {
    public List<List<String>> solveNQueens(int n) {
        List<List<String>> res = new ArrayList<>();
        helper(n, 0, new int[n], res);
        return res;
    }

    private void helper(int n, int row, int[] idxQueue, List<List<String>> res) {
        if(row == n) {
            List<String> item = new ArrayList<>();
            for(int i = 0; i < n; i++) {
                StringBuilder tmp = new StringBuilder();
                for(int j = 0; j < n; j++) {
                    if(idxQueue[i] == j) tmp.append('Q');
                    else tmp.append('.');
                }
                item.add(new String(tmp));
                // System.out.println(item);
            }
            res.add(item);
            return ;
        } else {
            for(int i = 0; i < n; i++) {
                idxQueue[row] = i;
                if(check(row, idxQueue)) {
                    System.out.println(row);
                    helper(n, row+1, idxQueue, res);
                }
            }
        }
    }

    private boolean check(int row, int[] idxQueue) {
        for(int i = 0; i < row; i++) {
            if(idxQueue[i] == idxQueue[row] || Math.abs(idxQueue[i] - idxQueue[row]) == row - i)
                return false;
        }
        return true;
    }

    public static void main(String[] args) {
        Solution solu = new Solution();
        List<List<String>> res = solu.solveNQueens(4);
        System.out.println(res);
    }
}
