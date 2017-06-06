public class Solution {
    public int rob(int[] nums) {
        if(nums.length == 0) return 0;
        int[] rob = new int[nums.length];
        
        for(int i = 0; i < nums.length; i++) {
            if(i == 0) rob[i] = nums[i];
            else if(i == 1) rob[i] = Math.max(nums[i], nums[i-1]);
            else rob[i] = Math.max(rob[i-1], rob[i-2] + nums[i]);
        }
        
        return rob[nums.length - 1];
    }
}
