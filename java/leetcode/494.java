// 691ms
class Solution {
    public int findTargetSumWays(int[] nums, int S) {
        return helper(nums, S, 0, 0);
    }
    
    int helper(int[] nums, int sum, int id, int ret) {
        if(id == nums.length) {
            if(sum == 0) ret++;
            return ret;
        }
        
        ret = helper(nums, sum-nums[id], id+1, ret);
        ret = helper(nums, sum+nums[id], id+1, ret);
        
        return ret;
    }
}

// 21ms
class Solution {
    public int findTargetSumWays(int[] nums, int S) {
        int sum = 0;
        for (int i = 0; i < nums.length; i++) {
            sum += nums[i];
        }
        if(S > sum || (sum + S) % 2 == 1)   return 0;
        return subsetSum(nums, (sum + S) / 2);
    }

    private int subsetSum(int[] nums, int S){
        int[] dp = new int[S + 1];
        dp[0] = 1;
        for (int i = 0; i < nums.length; i++) {
            for (int j = S; j >= nums[i]; j--) {
                dp[j] += dp[j - nums[i]];
            }
        }
        return dp[S];
    }
}
