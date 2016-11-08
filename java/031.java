//Next Permutation
public class Solution {
	public void nextPermutation(int[] nums) {
		boolean flag = false;

		for(int i = nums.length-1; i >= 1; i--) {
			if(nums[i] > nums[i-1]) {
				for(int j = nums.length-1; j >= i; j--)
					if(nums[i-1] < nums[j]) {
						int tmp = nums[j];
						nums[j] = nums[i-1];
						nums[i-1] = tmp;
						Arrays.sort(nums, i, nums.length);
						flag = true;
						break;
					}
				break;
			}
		}
		if(!flag) {
			int j = 0, k = nums.length-1;
			while(j < k) {
				int tmp = nums[j];
				nums[j] = nums[k];
				nums[k] = tmp;
				j++;k--;
			}
		}
	}
}
