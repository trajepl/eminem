public class WordDictionary {
    public class TrieNode {
        TrieNode[] children = new TrieNode[26];
        boolean isKey;
    }
    
    /** Initialize your data structure here. */
    TrieNode root=new TrieNode();;
    public WordDictionary() {
        this.root = new TrieNode();
    }
    
    /** Adds a word into the data structure. */
    public void addWord(String word) {
        TrieNode node = this.root;
        
        word = word.toLowerCase();
        for(char c : word.toCharArray()) {
            if(node.children[c-'a'] == null) 
                node.children[c-'a'] = new TrieNode();
            node = node.children[c-'a'];
        }
        node.isKey = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    public boolean search(String word) {
        return dfs(word, 0, root);
    }
    
    boolean dfs(String word, int id, TrieNode node) {
        for(int i = id; i < word.length(); i++) {
            if(word.charAt(i) == '.' && node !=null) {
                TrieNode tmp = node;
                for (int j = 0; j < 26; j++) {
                    node = tmp.children[j];
                    if(dfs(word, i + 1, node)) return true;
                }
            } else if(word.charAt(i) != '.' && node !=null) {
                node = node.children[word.charAt(i) - 'a'];
            }
        }
        return ((node !=null) && node.isKey);
    }
}

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * boolean param_2 = obj.search(word);
 */