public class Solution {
    public int majorityElement(int[] nums) {
        int candidate=0;
        int count = 0;
        for(int i: nums) {
            if(count == 0) {
                count = 1;
                candidate = i;
            } else if(i == candidate) {
                count += 1;
            } else 
                count -= 1;
        }
        return candidate;
    }
}

public class Solution {
    public int majorityElement(int[] nums) {
        int limit = nums.length / 2;
        Map<Integer, Integer> times = new HashMap<>();
        
        for(int i = 0; i < nums.length; i++) {
            if(times.containsKey(nums[i])) {
                times.put(nums[i], times.get(nums[i]) + 1);
            } else {
                times.put(nums[i], 1);
            }
            
            if(times.get(nums[i]) > limit) 
                    return nums[i];
        }
        return 0;
    }
}