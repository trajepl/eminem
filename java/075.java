public class Solution {
    public void sortColors(int[] nums) {
        int p1 = 0, p2 = 0;
        
        for(int i = 0; i < nums.length; i++) {
            int t = nums[i];
            nums[i] = 2;
            if(t <= 1) {
                nums[p2] = 1;
                p2++;
            }
            if(t == 0) {
                nums[p1] = 0;
                p1++;
            }
        }
    }
}
