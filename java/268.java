public class Solution {
	public int missingNumber(int[] nums) {
		int len = nums.length;
		int i = 0;
		while(i < len) {
			if(nums[i] != i && nums[i] < len) {
				int tmp = nums[i];
				nums[i] = nums[tmp];
				nums[tmp] = tmp;
			} else i++;
		}
		for(int i = 0; i < len; i++) {
			if(nums[i] != i) return i;
		}
		return i;
	}
}
