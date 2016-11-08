public class Solution {
	public int removeDuplicates(int[] nums) {
		int ret = 1;
		if(nums.length <= 1) return nums.length;

		for(int i = 1; i < nums.length; i++) {
			if(nums[i] != nums[i - 1]) {
				nums[ret] = nums[i];
				ret ++;
			}
		}
		return ret;
	}
}
