// 244ms
class Solution {
    public int subarraySum(int[] nums, int k) {
        int cnt = 0;
        int[] dp = new int[nums.length+1];
        dp[0] = 0;
        
        for(int i = 1; i <= nums.length; i++) {
            dp[i] = dp[i-1] + nums[i-1];
            if(dp[i] == k) cnt++;
        }
        
        for(int i = 1; i < nums.length; i++) {
            for(int j = i+1; j <= nums.length; j++) {
                if(dp[j] - dp[i] == k) cnt++;
            }
        }
        return cnt;
    }
}

// 40ms
public class Solution {
    public int subarraySum(int[] nums, int k) {
        int sum = 0, result = 0;
        Map<Integer, Integer> preSum = new HashMap<>();
        preSum.put(0, 1);
        
        for (int i = 0; i < nums.length; i++) {
            sum += nums[i];
            if (preSum.containsKey(sum - k)) {
                result += preSum.get(sum - k);
            }
            preSum.put(sum, preSum.getOrDefault(sum, 0) + 1);
        }
        
        return result;
    }
}
