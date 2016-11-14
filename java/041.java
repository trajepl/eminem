/*Method 1*/
public class Solution {
	public int firstMissingPositive(int[] nums) {
		Arrays.sort(nums);
		int i = 0, flag = 1;
		for(; i < nums.length && nums[i] <= 0; i++);
		for(; i < nums.length; i++) {
			if(flag == nums[i] + 1) continue;
			else return flag;
		}
		return flag;
	}
}

/*Methid 2*/
public class Solution {
    public int firstMissingPositive(int[] nums) {
        int len = nums.length;
        int i = 0;
        while(i < len) {
            if(nums[i] != i + 1 && nums[i] <= len && 
            	nums[i] > 0 && nums[i] != nums[nums[i]-1]) {
                int tmp = nums[i];
                nums[i] = nums[tmp-1];
                nums[tmp-1] = tmp;
            } else i++;
        }
        for(i = 0; i < len; i++) {
            if(nums[i] != i + 1) return i + 1;
        }
        return i+1;
    }
}