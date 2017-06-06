public class Solution {
    public List<List<Integer>> combinationSum3(int k, int n) {
        List<List<Integer>> res = new ArrayList<>();

        backtrack(res, new ArrayList<Integer>(), 1, k, n);
        return res;
    }

    private void backtrack(List<List<Integer>> res, List<Integer> tmp, int start, int num, int target) {
        if(target <= 9 && target >= start && num == 1) {
            tmp.add(target);
            res.add(new ArrayList<Integer>(tmp));
            tmp.remove(tmp.size()-1);
            return ;
        }

        for(int i = start; i < 10; i++) {
            tmp.add(i);
            backtrack(res, tmp, i+1, num-1, target - i);
            tmp.remove(tmp.size()-1);
        }

    }
}
