public class Solution {
    public int[] countBits(int num) {
        if(num <= 0) return new int[]{0};
        int[] dp = new int[num + 1];
        
        dp[0] = 0; dp[1] = 1;
        int flag = 2;
        for(int i = 2; i <= num; i++) {
            if(i % 2 == 0 && dp[i/2] == 1) {
                dp[i] = 1;
                flag = i;
            }
            else dp[i] = dp[flag] + dp[i - flag];
        }
        return dp;
    }
}

public class Solution {
    public int[] countBits(int num) {
        int[] ret = new int[num+1];
        for(int i=1; i<=num; i++)
        {
            ret[i] = ret[i>>1] + (i&1);
        }
        return ret;
    }
}
