public class Solution {
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> ret = new ArrayList<>();
        int len = nums.length;
        int cnt = 1 << len;
        
        for(int i = 0; i < cnt; i++) {
            List<Integer> item = new ArrayList<>();
            for(int j = 0; j < len; j++) {
                if(((1 << j) & i) != 0) {
                    item.add(nums[j]);
                }
            }
            ret.add(item);
        }
        return ret;
    }
}

public class Solution {
    public List<List<Integer>> subsets(int[] nums) {
    List<List<Integer>> list = new ArrayList<>();
    Arrays.sort(nums);
    backtrack(list, new ArrayList<>(), nums, 0);
    return list;
}

private void backtrack(List<List<Integer>> list , List<Integer> tempList, int [] nums, int start){
    list.add(new ArrayList<>(tempList));
    for(int i = start; i < nums.length; i++){
        tempList.add(nums[i]);
        backtrack(list, tempList, nums, i + 1);
        tempList.remove(tempList.size() - 1);
    }
}
}