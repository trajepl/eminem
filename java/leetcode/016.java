public class Solution {
    public int threeSumClosest(int[] nums, int target) {
        Arrays.sort(nums);
        int ret = 0;
        int distance = Integer.MAX_VALUE;
        for(int i = 0; i < nums.length - 2; i++) {
            int j = i + 1;
            int k = nums.length - 1;
            
            while(j < k) {
                int tmp = nums[i] + nums[j] + nums[k];
                int dis = Math.abs(tmp-target);
                if(dis == 0) return target;
                
                if(dis < distance) {
                    distance = dis;
                    ret = tmp;
                } 
                int t = (tmp < target)?j++:k--;
            }
        }
        return ret;
    }
}