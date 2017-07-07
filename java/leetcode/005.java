public class Solution {
    private int left = 0, maxlen = 0;
    
    public String longestPalindrome(String s) {
        char[] s_ = s.toCharArray();
        int len = s_.length;
        if(len < 2) return s;
        
        for(int i = 0; i < len-1; i++) {
            extendPalindrome(s_, i, i);
            extendPalindrome(s_, i, i+1);
        }
        return s.substring(left, left + maxlen);
    }
    
    private void extendPalindrome(char[] s, int l, int k) {
        while(l >= 0 && k < s.length && s[l] == s[k]) {
            l--; k++;
        }
        if(maxlen < k - l - 1) {
            left = l + 1;
            maxlen = k - l - 1;
        }
    }
}
