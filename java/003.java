public class Solution {
	public int lengthOfLongestSubstring(String s) {
		int i = 0, j = 0;
		int ret = 0;
		char[] str = s.toCharArray();
		int n = str.length;
		boolean[] flag = new boolean[256];
		while(j < n) {
			ret = Math.max(ret,  j - i);
			if(flag[str[j]]) {
				while(str[i] != str[j]) {
					flag[str[i]] = false;
					i++;
				}
				i++; j++;
			} else {
				flag[str[j]] = true;
				j++;
			}
		}
		return Math.max(ret, n - i);
	}
}
