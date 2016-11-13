public class Solution {
    List<List<Integer>> ret = new ArrayList<>();
    int cans;
    public List<List<Integer>> combine(int n, int k) {
        cans = n;
        backTracking(new ArrayList<Integer>(), 1, k);
        return ret;
    }
    
    public void backTracking(List<Integer> cur, int start, int k) {
        if(k <= 0) {
            List<Integer> list = new ArrayList<>(cur);
            ret.add(list);
        } else {
            for(int i = start; i <= cans; i++ ) {
                cur.add(i);
                backTracking(cur, i+1, k - 1);
                cur.remove(new Integer(i));
            }
        }
    }
}