public class Solution {
    public int largestRectangleArea(int[] height) {
        Stack<Integer> s = new Stack<>();
        int sum = 0;
        
        int[] heights = new int[height.length + 1];
        for(int i = 0; i < height.length; i++) heights[i] = height[i];
        heights[height.length] = 0;
        
        for(int i = 0; i < heights.length;) {
            if(s.isEmpty() || heights[i] > heights[s.peek()]) {
                s.push(i); i++;
            } else {
                int tmp = s.peek();
                s.pop();
                sum = Math.max(sum, heights[tmp] *(s.isEmpty()?i:i - s.peek() - 1));
            }
        }
        return sum;
    }
}
