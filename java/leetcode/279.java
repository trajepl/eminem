public class Solution {
    public int numSquares(int n) {
        int[] dp = new int[n+1];
        dp[0] = 0; dp[1] = 1;
        
        for(int i = 2; i <= n; i++) {
            int min = i;
            if(Math.sqrt(i) % 1 <= 0.000000001) {
                dp[i] = 1;
                continue;
            }
            for(int j = i-1; j >= i / 2; j--) {
                min = Math.min(dp[j]+dp[i-j], min);
            }
            dp[i] = min;
        }
        return dp[n];
    }
    
    // static boolean isSqrt(double num){
    //     String regex = "\\d+.0+";
    //     return(Math.sqrt(num)+"").matches(regex);
    // }
}

public class Solution {
    public int numSquares(int n) {
        int[] dp = new int[n + 1];
        Arrays.fill(dp, Integer.MAX_VALUE);
        dp[0] = 0;
        for(int i = 1; i <= n; ++i) {
            int min = Integer.MAX_VALUE;
            int j = 1;
            while(i - j*j >= 0) {
                min = Math.min(min, dp[i - j*j] + 1);
                ++j;
            }
            dp[i] = min;
        }
        return dp[n];
    }
}
