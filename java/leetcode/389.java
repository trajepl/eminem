public class Solution {
    public char findTheDifference(String s, String t) {
        char[] s_ = s.toCharArray();
        char[] t_ = t.toCharArray();
        int s_sum = 0, t_sum = 0;
        int i=0;
        for(;i<s_.length;i++){
            s_sum += s_[i];
            t_sum += t_[i];
        }
        t_sum += t_[i];
        return (char)(t_sum - s_sum);
    }
}
