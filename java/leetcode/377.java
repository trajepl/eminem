public class Solution {
    public int combinationSum4(int[] nums, int target) {
        int[] dp = new int[target + 1];
        dp[0] = 0;
        
        Set<Integer> set = new HashSet<>();
        for(int i: nums) set.add(i);
        
        for(int i = 1; i <= target; i++) {
            if(set.contains(i)) {
                dp[i] += 1;
                // System.out.println(i + ":" + i + "+0" + "-" +dp[i]);
            }
            
            for(int j = i-1; j >= 1; j--) {
                if(set.contains(j)) {
                    dp[i] += dp[i-j];
                    // System.out.println(i + ":" + j + "+" + (i-j) + "-" + dp[i]);
                }
            }
        }
        
        return dp[target];
    }
}


public class Solution {
    public int combinationSum4(int[] nums, int target) {
        
        Arrays.sort(nums);
        
        int[] dp = new int[target + 1];
        dp[0] = 1;
        for (int i = 1; i <= target; i++){
            
            for (int num : nums){
                if (num > i) break;
                dp[i] += dp[i - num];
            }
            
        }
        return dp[target];
    }
}
