// x ^ x = 0
// x ^ 0 = x
// x ^ a ^ b = x ^ (a ^ b)

public class Solution {
    public int singleNumber(int[] nums) {
        int n = nums.length;
        int res = nums[0];
        for(int i=1;i<n;i++)
            res ^= nums[i];
        return res;
    }
}

public class Solution {
    public int singleNumber(int[] nums) {
        Map<Integer, Integer> count = new HashMap<>();
        
        for(int i: nums) {
            if(count.containsKey(i)) count.put(i, 2);
            else count.put(i, 1);
        }
        
        int res = 0;
        for(int key: count.keySet()) {
            if(count.get(key) == 1) res = key;
        }
        return res;
    }
}
