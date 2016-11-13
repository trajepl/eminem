/*Recusive*/
public class Solution {
	List<List<Integer>> ret = new ArrayList<>();
	int[] cans = {};

	public List<List<Integer>> combinationSum(int[] candidates, int target) {
		this.cans = candidates;
		Arrays.sort(cans);
		backTracking(new ArrayList<>(), 0, target);
		return ret;
	}

	public void backTracking(ArrayList<Integer> cur, int index, int target) {
		if(target == 0) {
			List<Integer> list = new ArrayList<>(cur);
			ret.add(list);
		} else {
			for(int i = index; i < cans.length && target <= cans[i]; i++) {
				cur.add(cans[i]);
				backTracking(cur, i, target - cans[i]);
				cur.remove(new Integer(cans[i]));
			}
		}
	}
}

/*Non-recusive*/
