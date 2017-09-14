class Solution {
    public int minDistance(String word1, String word2) {
        return word1.length() + word2.length() - 2 * lcs(word1.toCharArray(), word2.toCharArray());
    }
    
    int lcs(char[] word1, char[] word2) {
        int[][] dp = new int[word1.length+1][word2.length+1];
        
        for(int i = 1; i <= word1.length; i++) {
            for(int j = 1; j <= word2.length; j++) {
                if(word1[i-1] == word2[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = Math.max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        
        return dp[word1.length][word2.length];
    }
}
