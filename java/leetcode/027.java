public class Solution {
	public int removeElement(int[] nums, int val) {
		if(nums.length == 0) return 0;

		int ret == 0;
		for(int i = 0; i < nums.length; i++) {
			if(nums[i] != val) nums[ret++] = nums[i];
		}
		return ret;
	}
}
