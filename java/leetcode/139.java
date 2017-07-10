/* 看到这题第一反应是DFS枚举查找，直到“探”到string尾部则算成功。但题目并不要求给出是如何break的，而只要判断是否能break。对这类判断“是”与“否”的可以用DFS暴力解决的题，可以尝试用DP做book keeping中间判断状态，避免DFS的反复搜索。比如这题，可以用一个数组dp记录S[0:i]是否能break。

dp[i]：S[0:i-1]是否能被break。例如dp[1]表示s[0]是否能被break。
dp[0] = true
dp[i] = true if and only if:
1. 存在一个i-1>=k>=0，使s[k:i-1]存在于dict中。
2. s[0: k-1]可以被break，即dp[k] = true。
*/
public class Solution {
    public boolean wordBreak(String s, List<String> wordDict) {
        boolean[] flag = new boolean[s.length() + 1];
        flag[0] = true;
        
        for(int i = 1; i < flag.length; i++) {
            for(int j = 0; j < i; j++) {
                if(flag[j] && wordDict.contains(s.substring(j, i))) {
                    flag[i] = true;
                    break;
                }
            }
        }
        
        return flag[s.length()];
    }
}
