// 0ms
public class Solution {
    public int numTrees(int n) {
        if(n <= 1) return 1;
        int[] nums = new int[n+1];
        nums[0] = 1; nums[1] = 1;
        
        for(int i = 2; i <= n; i++) 
            for(int j = 0; j < i; j++) 
                nums[i] += nums[j] * nums[i-j-1];
            
        return nums[n];
    }
}


// The Time Exceeded
public class Solution {
    public int numTrees(int n) {
        if(n < 1) return 1;
        return helper(1, n);
    }
    
    private int helper(int start, int end) {
        int cnt = 0;
        if(start == end) {
            return 1;
        } 
        
        for(int i = start; i <= end; i++) {
            int left = helper(start, i - 1);
            int right = helper(i + 1, end);
            if(left == 0 || right == 0) cnt += right + left;
            else cnt += left * right;
        }
        return cnt;
    }
}
