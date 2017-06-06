public class Solution {
	public int maxProfit(int[] prices) {
		int min = Integer.MAX_VALUE, ret = 0;
		int len = prices.length;

		for(int i = 0; i < len; ) {
			while(i < len && prices[i] >= min) {
				ret = Math.max(ret, prices[i] - min);
				++i;
			}
			if(i >= len) return ret;
			else min = prices[i];
		}
		return ret;
	}
}
