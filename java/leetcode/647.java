class Solution {
    public int countSubstrings(String s) {
        if (s == null || s.length() == 0) {
            return 0;
        }
        int n = s.length(); 
        int res = 0;
        for (int i = 0; i < n; i++) {
            res += get(s, i, i) + get(s, i, i + 1);
        }
        return res;
    }
    
    private int get(String s, int i, int j) {
        int count = 0;
        while (i >= 0 && j < s.length() && s.charAt(i) == s.charAt(j)) {
            count++;i--;j++;
        }
        return count;
    }
}

class Solution {
    public int countSubstrings(String s) {
        int cnt = 0;
        char[] str = s.toCharArray();
        int[][] dp = new int[str.length][str.length];
        boolean[][] flag = new boolean[str.length][str.length];
        
        for(int i = 0; i < str.length; i++) {
            dp[i][i] = 1;
            flag[i][i] = true;
            cnt++;
        }
        
        for(int i = 0; i < str.length - 1; i++) {
            for(int j = i + 1; j < str.length; j++) {
                if(flag[i][j-1] && str[j] == str[j-1]) {
                    flag[i][j] = true;
                    dp[i][j] = 1;
                    cnt++;
                }
                if(dp[i][j-1] > 0) continue;
                if(isPalindromic(s.substring(i, j+1))) {
                    dp[i][j] =  1;
                    cnt++;
                }
            }
        }
        return cnt;         
        
    }
    
    boolean isPalindromic(String s) {
        char[] str = s.toCharArray();
        for(int i = 0 ; i < str.length; i++) {
            if(str[i] != str[str.length - i - 1]) return false;
        }
        return true;
    }
}
