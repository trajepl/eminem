public class RegxMatch {
    public boolean isMatch(String t, String p) {
        return helper(t, p, 0, 0);
    }

    public boolean helper(String s, String p, int i, int j) {
        if(j==p.length())  
            return i==s.length();  
        
        if(j==p.length()-1 || p.charAt(j+1) != '*')  
            if(i==s.length()||s.charAt(i)!=p.charAt(j) && p.charAt(j)!='.')  
                return false;  
            else  
                return helper(s,p,i+1,j+1);  
  
        
        while(i < s.length() && (p.charAt(j)=='.' || s.charAt(i)==p.charAt(j)))  {  
            if(helper(s,p,i,j+2))  
                return true;  
            i++;  
        }  
        return helper(s,p,i,j+2); 
    }
    
    public boolean isMatchDP(String t, String p) {
        if(t == null || p == null) return false;

        boolean[][] dp = new boolean[t.length()+1][p.length()+1];
        dp[0][0] = true;

        for(int i = 0; i < p.length(); i++)
            if(p.charAt(i) == '*' && dp[0][i-1])
                dp[0][i+1] = true;

        for(int i = 0; i < t.length(); i++)
            for(int j = 0; j < p.length(); j++) {
                if(t.charAt(i) == p.charAt(j) || p.charAt(j) == '.')
                    dp[i+1][j+1] = dp[i][j];

                if(p.charAt(j) == '*') {
                    if(p.charAt(j-1) != t.charAt(i) && p.charAt(j) != '.')
                        dp[i+1][j+1] = dp[i+1][j-1];
                    else
                        dp[i+1][j+1] = (dp[i][j+1] || dp[i+1][j-1] || dp[i+1][j]);
                }
            }
        return dp[t.length()][p.length()];
    }

    public static void main(String[] args) {
        String t = "aab";
        String p = "c*a*b";
        RegxMatch reg = new RegxMatch();
        System.out.println(reg.isMatch(t, p));
        System.out.println(reg.isMatchDP(t, p));
    }
}
