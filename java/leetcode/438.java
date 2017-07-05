// 14ms
public class Solution {
    public List<Integer> findAnagrams(String s, String p) {
        char[] s_ = s.toCharArray();
        char[] p_ = p.toCharArray();
        int[] hash = new int[256];
        
        int left = 0, right = 0, count = p_.length;
        
        for(char c: p_) {
            hash[c]++;
        }
        
        List<Integer> ret = new ArrayList<>();
        
        while(right < s_.length) {
            if(hash[s_[right++]]-- > 0) count--;
            if(count == 0) ret.add(left);
            if(right - left == p_.length && hash[s_[left++]]++ >= 0) count++;
        }
        
        return ret;
    }
}

// 333ms
public class Solution {
    public List<Integer> findAnagrams(String s, String p) {
        char[] s_ = s.toCharArray();
        char[] p_ = p.toCharArray();
        int[] hash = new int[256];

        int count = p_.length;

        for(char c: p_) {
            hash[c]++;
        }

        List<Integer> ret = new ArrayList<>();
        for(int i = 0; i <= s_.length - count; i++) {
            if(hash[s_[i]] != 0) {
                int[] hash_tmp = Arrays.copyOf(hash, 256);
                int j = 0;
                for(; j < count && hash_tmp[s_[i+j]] != 0; j++) {
                    hash_tmp[s_[i+j]]--;
                }
                if(j == count) ret.add(i);
            }
        }

        return ret;
    }
}
