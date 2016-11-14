/* Stack */
public class Solution {
	public int trap(int[] height) {
		int n = height.length;
		Stack<Integer> s = new Stack<Integer>();
		s.push(0);
		int water = 0;

		for(int i = 1; i < height.length; i++) {
			if(height[i] > height[s.peek()]) {
				int bottom = height[s.pop()];
				while(!s.isEmpty() && height[i] >= height[s.peed()]) {
					water += (height[s.peek()] - bottom) * (i - s.peek() - 1);
					bottom = height[s.pop()];
				}
				if(!s.isEmpty()) water += (height[i] - bottom) * (i - s.peek() - 1);
			}
			s.push(i);
		}
		return water;
	}
}

/* Two pointer */
public class Solution {
    public int trap(int[] height) {
        int n = height.length;
        int[] left = new int[n];
        int[] right = new int[n];
        
        int water = 0;
        for(int i = 1; i < n; i++)
            left[i] = Math.max(left[i - 1],  height[i - 1]);
            
        for(int i = n - 2; i >= 0; i--) {
            right[i] = Math.max(right[i+1], height[i + 1]);
            int min = Math.min(left[i], right[i]);
            if(min > height[i]) water += min - height[i];
        }
        return water;
    }
}