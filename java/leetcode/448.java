public class Solution {
	public List<Integer> findDisappearedNumbers(int[] nums) {
		int len = nums.length;
		List<Integer> list = new LinkedList<>();
		for(int i = 1; i <= len; i++) list.add(i);
		for(int i = 0; i < len;  i++) list.remove(new Integer(nums[i]));
		return list;
	}
}
