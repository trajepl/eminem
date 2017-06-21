public class Solution {
    public boolean detectCapitalUse(String word) {
        int i = 0;
        for(char c : word.toCharArray()){
            if('Z' - c >= 0){
                i++;
            }
        }
        
        return ((i==0 || i==word.length()) || (i==1 && 'Z' - word.charAt(0)>=0));
    }
}
