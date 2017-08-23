You have two arrays of strings, words and parts. Return an array that contains the strings from words, modified so that any occurrences of the substrings from parts are surrounded by square brackets [], following these guidelines:

If several parts substrings occur in one string in words, choose the longest one. If there is still more than one such part, then choose the one that appears first in the string.

## Example

For words = ["Apple", "Melon", "Orange", "Watermelon"] and parts = ["a", "mel", "lon", "el", "An"], the output should be
findSubstrings(words, parts) = ["Apple", "Me[lon]", "Or[a]nge", "Water[mel]on"].

While "Watermelon" contains three substrings from the parts array, "a", "mel", and "lon", "mel" is the longest substring that appears first in the string.

## Input/Output

- [time limit] 3000ms (java)
- [input] array.string words

An array of strings consisting only of uppercase and lowercase English letters.

Guaranteed constraints:
```
0 ≤ words.length ≤ 104,
1 ≤ words[i].length ≤ 30.
```

- [input] array.string parts

An array of strings consisting only of uppercase and lower English letters. Each string is no more than 5 characters in length.

Guaranteed constraints:
```
0 ≤ parts.length ≤ 105,
1 ≤ parts[i].length ≤ 5,
parts[i] ≠ parts[j].
```

- [output] array.string

```java
//Execution time limit exceeded
String[] findSubstringsError(String[] words, String[] parts) {
    String[] rets = new String[words.length];
    int i = 0;
    for(String word: words) {
        int len = 0, pos = word.length();
        StringBuffer ret = new StringBuffer(word);
        for(String part: parts) {
            int startPos = word.indexOf(part);
            if(startPos >=0) {
                if(startPos < pos && len == part.length() || part.length() > len) {
                    pos = startPos;
                    ret = new StringBuffer(word);
                    len = part.length();
                    ret.insert(pos+len, ']');
                    ret.insert(pos, '[');
                }
            }
        }
        rets[i++] = ret.toString();
    }
    return rets;
}

// Trie implement
class Trie {
    /** Initialize your data structure here. */
    private class Node{
        Node[] children = new Node[128];
        boolean isKey = false;
    }
    
    Node root;
    public Trie() {
        root = new Node();
    }
    
    public void insert(String word) {
        Node node = root;
        for(char c: word.toCharArray()) {
            if(node.children[c] == null) 
                node.children[c] = new Node();
            node = node.children[c];
        }
        node.isKey = true;
    }

    String findSubstrings(String word) {
        int maxLen = 0, splitStart = 0, splitEnd = 0;
        char[] str = word.toCharArray();
        for(int i = 0; i < str.length; i++) {
            Node node = root;
            int j = i;
            for(; j < str.length; j++) {
                char letter = str[j];
                if(node.children[letter] == null) break;
                node = node.children[letter];
                int len = j - i + 1;
                if(node.isKey && len > maxLen) {
                    maxLen = len;
                    splitStart = i;
                }
            }

        }
        if(maxLen == 0) return word;
        return word.substring(0, splitStart) + "[" +
            word.substring(splitStart, splitStart + maxLen) + "]" + 
            word.substring(splitStart + maxLen, str.length);
    }
}
    
String[] findSubstrings(String[] words, String[] parts) {
    Trie root = new Trie();
    for(String part: parts) {
        root.insert(part);
    }
    
    String[] rets = new String[words.length];
    for(int i = 0; i < words.length; i++) {
        rets[i] = root.findSubstrings(words[i]);
    }
    
    return rets;
}
```
