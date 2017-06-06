public class Solution {
    public int maxArea(int[] height) {
        int max = 0;
        int p1 = 0, p2 = height.length - 1;
        while(p1 < p2) {
            max = Math.max((p2-p1) * Math.min(height[p1], height[p2]), max);
            if(height[p1] <= height[p2])
                p1 ++;
            else p2--;
        }
        return max;
    }
}
