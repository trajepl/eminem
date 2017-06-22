public class Solution {
    public boolean canConstruct(String ransomNote, String magazine) {
        if(magazine==null || magazine.length()<ransomNote.length())
            return false;
        int[] arr = new int[26];
        for( char ch : magazine.toCharArray()){
            arr[ch-'a'] +=1;
        }
         
        for( char ch : ransomNote.toCharArray()){
            arr[ch-'a']-=1;
            if(arr[ch-'a'] < 0)
                return false;
        }
        return true;
    }
}
