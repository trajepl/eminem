public class Solution {
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        List<List<Integer>> ret = new ArrayList<>();
        Arrays.sort(nums);
        backtrack(ret, new ArrayList<Integer>(), nums, 0);
        return ret;
    }

    private void backtrack(List<List<Integer>> ret, List<Integer> tmp, int[] nums, int start) {
        ret.add(new ArrayList<>(tmp));

        for(int i = start; i < nums.length; i++) {
            if(i == start || nums[i] != nums[i-1]) {
                tmp.add(nums[i]);
                backtrack(ret, tmp, nums, i + 1);
                tmp.remove(tmp.size() - 1);
            }

        }
    }
}
