public class Solution {
    public List<String> addOperators(String num, int target) {
        List<String> res = new LinkedList<>();
        if(num == null && num.length() == 0) return res;
        char[] numChr = num.toCharArray();
        helper(res, numChr, "", target, 0, 0, 0);
        return res;
    }
    
    public void helper(List<String> res, char[] numChr, String solu, int target, long val, int idx, long multed) {
        if(idx == numChr.length && target == val) {
            res.add(solu);
            return ;
        }
        long cur = 0;
        for(int i = idx; i < numChr.length; i++) {
            if(i != idx && numChr[idx] == '0') break;
            cur = cur * 10 + numChr[i] - '0';
            if(idx == 0) 
                helper(res, numChr, solu + cur, target, cur, i+1, cur);
            else {
                helper(res, numChr, solu + "+" + cur, target, val+cur, i+1, cur);
                helper(res, numChr, solu + "-" + cur, target, val-cur, i+1, -cur);
                helper(res, numChr, solu + "*" + cur, target, val-multed+multed*cur, i+1, multed*cur);
            }
        }
    }
}