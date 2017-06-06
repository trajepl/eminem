/* Method 1 */
public class Solution {
	public int jump(int[] nums) {
		int len = nums.length - 1;
		int ret = 0;

		for(int i = 0; i < len - 1;) {
			if(nums[i] + i >= len) return ++ret;
			int max = 0;
			int j = i + 1;
			for(; j < i + nums[i]; j++) {
				if(nums[j] + j > nums[max] + max) max = j;
			}
			ret++;
			i = max;
		}
		return ret;
	}
}

/* Method 2(nice) */
public class Solution {
	public int jump(int[] nums) {
		int len = nums.length;
		int ret = 0;
		int last = 0;
		int curr = 0;
		for(int i = 0; i < n; i++) {
			if(i > last) {
				last = curr;
				++ret;
			}
			cur = Math.max(curr, i + nums[i]);
		}
		return ret;
	}
}
