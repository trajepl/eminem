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

public class Solution {
    public int maximalRectangle(char[][] matrix) {
        if (matrix == null || matrix.length == 0 || matrix[0].length == 0) return 0;
        int m = matrix.length, n = matrix[0].length, max = 0;
        
        int[] heights = new int[n];
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                heights[j] = (matrix[i][j] == '0') ? 0 : heights[j] + 1;
            }
            for(int j = 0; j < n; j++) {
                if(heights[j] == 0) continue;
                int left = j, right = j;
                while(left >= 0 && heights[left] >= heights[j]) left--;
                left++;
                while(right < n && heights[right] >= heights[j]) right++;
                right--;
                
                int width = right - left + 1;
                max = Math.max(max, heights[j] * width);
            }
        }
        return max;
    }
}
