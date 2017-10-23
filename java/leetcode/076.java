public class Solution {
    public String minWindow(String s, String w) {
        char[] str1 = s.toCharArray();
        char[] str2 = w.toCharArray();

        int[] map = new int[128];
        for(char c: str2) {
            map[c]++;
        }
        
        int cnt = str2.length;
        int begin = 0, end = 0;
        int interval = Integer.MAX_VALUE, head = 0;

        while(end < str1.length) {
            if(map[str1[end++]]-- > 0) cnt--;
            while(cnt == 0) {
                if(end - begin < interval) {
                    interval = end - begin;
                    head = begin;
                }
                if(map[str1[begin++]]++ == 0) cnt++;
            }
        }
        return interval == Integer.MAX_VALUE ? "" : s.substring(head, head+interval);
    }
}
