public class Trie {

    /** Initialize your data structure here. */
    private class Node{
        Node[] children = new Node[26];
        boolean isKey = false;
    }
    
    
    Node root;
    public Trie() {
        root = new Node();
    }
    
    /** Inserts a word into the trie. */
    public void insert(String word) {
        Node node = root;
        for(char c: word.toCharArray()) {
            if(node.children[c-'a'] == null) 
                node.children[c-'a'] = new Node();
            node = node.children[c-'a'];
        }
        node.isKey = true;
    }
    
    /** Returns if the word is in the trie. */
    public boolean search(String word) {
        char[] chr = word.toCharArray();
        Node node = root;
        for(char c : chr) {
            if(node.children[c-'a'] != null) {
                node = node.children[c-'a'];
            } else {
                return false;
            }
        }
        return node!=null && node.isKey;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    public boolean startsWith(String prefix) {
        Node node = root;
        for(char c: prefix.toCharArray()) {
            if(node != null && node.children[c-'a'] != null) 
                node = node.children[c-'a'];
            else return false;
        }
        return true;
    }
}

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * boolean param_2 = obj.search(word);
 * boolean param_3 = obj.startsWith(prefix);
 */