public class Solution {
    List<List<Integer>> ret = new ArrayList<>();
    int[] cans = {};
    public List<List<Integer>> permute(int[] nums) {
        cans = nums;
        int len = nums.length;
        List<Integer> numsList = new ArrayList<>();
        for(int i = 0; i < nums.length; i++) {
            numsList.add(nums[i]);
        }
        backTracking(new ArrayList<>(), numsList, len);
        return ret;
    }
    
    public void backTracking(List<Integer> cur, List<Integer> numsList, int len) {
        if(len == 0) {
            List<Integer> list = new ArrayList<>(cur);
            ret.add(list);
        } else {
            for(int i = 0; i < len; i++) {
                int tmp = numsList.get(i);
                cur.add(tmp);
                numsList.remove(i);
                backTracking(cur, numsList, len-1);
                numsList.add(i, tmp);
                cur.remove(new Integer(tmp));
            }
        }
    }
}