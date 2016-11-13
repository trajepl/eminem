public class Solution {
    public List<List<Integer>> ret = new ArrayList<>();
    public int[] cans = {};

    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        cans = candidates;
        Arrays.sort(cans);
        backTracking(new ArrayList<>(), 0, target);  
        return ret;
    }
    
    public void backTracking(List<Integer> cur, int start, int target) {
        if(target == 0) {
            List<Integer> list = new ArrayList<>(cur);  
            ret.add(list);  
        } else {
            for(int i = start; i < cans.length && target >= cans[i]; i++) {
                cur.add(cans[i]);
                backTracking(cur, i+1, target - cans[i]);
                cur.remove(new Integer(cans[i]));
                while(i < cans.length-1 && cans[i] == cans[i+1]) i++;
            }
        }
        
    }
}