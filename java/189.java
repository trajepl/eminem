public class Solution {
    public void rotate1(int[] nums, int k) {a
        if(nums.length==1){
            return;
        }
        k = k % nums.length;
        int[] results = new int[nums.length];
        System.arraycopy(nums, 0, results, k, nums.length-k);
        System.arraycopy(nums, nums.length-k, results, 0, k);
        System.arraycopy(results, 0, nums, 0, nums.length);
    }

    public void rotate2(int[] nums, int k) {
        k %= nums.length;
        reverse(nums, 0, nums.length - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, nums.length - 1);
    }

    public void reverse(int[] nums, int start, int end) {
        while (start < end) {
            int temp = nums[start];
            nums[start] = nums[end];
            nums[end] = temp;
            start++;
            end--;
        }
    }
}
