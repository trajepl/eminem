public class Solution {
    public String reverseWords(String s) {
        String words[] = s.split(" ");
        StringBuilder reversedString = new StringBuilder();
        
        for(String word: words){
            String reversedWord = new StringBuffer(word).reverse().toString() + " ";
            reversedString.append(reversedWord);
        }
        
        return reversedString.toString().trim();

    }
}
