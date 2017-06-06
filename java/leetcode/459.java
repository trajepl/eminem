public class Solution {
    // 43ms
    public boolean repeatedSubstringPattern(String str) {
    	int l = str.length();
    	for(int i=l/2;i>=1;i--) {
    		if(l%i==0) {
    			int m = l/i;
    			String subS = str.substring(0,i);
    			StringBuilder sb = new StringBuilder();
    			for(int j=0;j<m;j++) {
    				sb.append(subS);
    			}
    			if(sb.toString().equals(str)) return true;
    		}
    	}
    	return false;
    }

    // 46ms kmp
    public boolean repeatedSubstringPattern(String str) {
        //This is the kmp issue
        int[] prefix = kmp(str);
        int len = prefix[str.length()-1];
        int n = str.length();
        System.out.println(len);
        return (len > 0 && n%(n-len) == 0);
    }
    private int[] kmp(String s){
        int len = s.length();
        int[] ret = new int[len];   
        int flag = 0;
        
        ret[0] = 0;
        
        for(int i = 1; i < len; i++) {
            while(flag > 0 && s.charAt(i)!= s.charAt(flag)) 
                flag = ret[flag-1];
            if(s.charAt(i) == s.charAt(flag)) flag++;
            ret[i] = flag;
        }
        return ret;
    }

    // 252ms
    public boolean repeatedSubstringPattern(String s) {
        int idx = 1;

        while(idx < s.length()) {
            int i = 0;
            while(i+idx < s.length() && s.charAt(i) == s.charAt(i+idx)) {
                i++;
            }
            if(i + idx == s.length() && s.length() % idx == 0) return true;
            idx++;
        }
        return false;
    }
}
