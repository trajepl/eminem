public class Solution {
    public int maximalRectangle(char[][] matrix) {
        int cols = matrix[0].length;
        int[] height = new int[cols];
        int j, ret = 0;
        for(int i = 0; i < matrix.length; i++) {
            for(j = 0; j < cols; j++) {
                if(i == 0)
                    height[j] = matrix[i][j]-'0';
                else {
                    if(matrix[i][j]-'0' == 0) {
                        height[j] = 0;
                    } else {
                        height[j] += matrix[i][j]-'0';
                    }
                }
            }

            int sum = largestRectangleArea(height);
            ret = Math.max(ret, sum);
        }

        return ret;
    }

    public int largestRectangleArea(int[] height) {
        Stack<Integer> s = new Stack<>();
        int sum = 0;
        int len = height.length;

        for(int i = 0; i < height.length;) {
            if(s.isEmpty() || height[i] > height[s.peek()]) {
                s.push(i); i++;
            } else {
                int tmp = s.pop();
                sum = Math.max(sum, height[tmp] *(s.isEmpty()?i:i - s.peek() - 1));
            }

            if (i == height.length) {
                while(!s.isEmpty()) {
                    int tmp = s.pop();
                    sum = Math.max(sum, height[tmp] *(s.isEmpty()?i:i - s.peek() - 1));
                }
            }
        }
        return sum;
    }
}