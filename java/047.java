public class Solution {

    public List<List<Integer>> permuteUnique(int[] nums) {

        List<List<Integer>> res = new ArrayList<>();

        Arrays.sort(nums);

        dfs(nums, res, new boolean[nums.length], new ArrayList<>());

        return res;

    }

    

    private void dfs(int[] nums, List<List<Integer>> res, boolean[] flag, List<Integer> tmp) {

        if(tmp.size() == nums.length) {

            res.add(new ArrayList<>(tmp));

            return ;

        }

        

        for(int i = 0; i < nums.length; i++) {

            if(flag[i] == true) continue;

            if(i > 0 && nums[i-1] == nums[i] && !flag[i-1]) continue;

            tmp.add(nums[i]);

            flag[i] = true;

            dfs(nums, res, flag, tmp);

            tmp.remove(tmp.size() - 1);

            flag[i] = false;

        }

    }

}
