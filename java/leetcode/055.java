public class Solution {
	public boolean canJump(int[] nums) {
		int len = nums.length;
		int curr = 0;
		for(int i = 0; i <= curr && i < len; i++) {
			curr = Math.max(curr, i + nums[i]);
		}

		if(curr < len -1) return false;
		return true;
	}
	
}
