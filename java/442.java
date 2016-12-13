public class Solution {
	public List<Integer> findDuplicates(int[] nums) {
		List<Integer> ret = new ArrayList<>();
		int[] duplicates = new int[nums.length];

		for(int num: nums) {
			if(duplicate[num-1] == 1) ret.add(num);
			else duplicate[num-1]++;
		}
		return ret;
	}
}
