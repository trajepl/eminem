public class Solution {
    public boolean isMath(String str, String pat) {
        int s = 0, p = 0, match = 0, starIdx = -1;
        int m = s.length(), n = p.length();
        while(s < m) {
            if(p < n && (str.charAt(s) == pat.charAt(p) || pat.charAt(p) == '?')) {
                s++; p++;
            } else if(p < n && (pat.charAt(p) == '*')) {
                match = s;
                starIdx = p;
                p++;
            } else if(starIdx != -1) {
                p = statIdx + 1;
                match++;
                s = match;
            } else return false;
        }
        while(p < n && pat.charAt(p) == '*') p++;
        return p == pattern.length();
    }
}

public class Solution {
    public boolean isMatch(String s, String p) {
        boolean[][] match=new boolean[s.length()+1][p.length()+1];
        match[s.length()][p.length()]=true;
        for(int i=p.length()-1;i>=0;i--){
            if(p.charAt(i)!='*')
                break;
            else
                match[s.length()][i]=true;
        }
        for(int i=s.length()-1;i>=0;i--){
            for(int j=p.length()-1;j>=0;j--){
                if(s.charAt(i)==p.charAt(j)||p.charAt(j)=='?')
                        match[i][j]=match[i+1][j+1];
                else if(p.charAt(j)=='*')
                        match[i][j]=match[i+1][j]||match[i][j+1];
                else
                    match[i][j]=false;
            }
        }
        return match[0][0];
    }
}
