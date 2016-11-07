public class Solution {
   public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> ret = new ArrayList<>();
        if(nums.length < 3) return ret;

        Arrays.sort(nums);
        for(int i = 0; i < nums.length-2; i++) {
            int j = i + 1;
            int k = nums.length - 1;
            while(j < k) {
                if(nums[i] + nums[j] + nums[k] == 0) {
                    // List<Integer> curr=Arrays.asList(nums[i], nums[j], nums[k]);
                    ret.add(Arrays.asList(nums[i], nums[j], nums[k]));
                    j++;
                    k--;
                    while(j < k && nums[j-1] == nums[j]) j++;
                    while(j < k && nums[k+1] == nums[k]) k--;
                } else if (nums[i]  + nums[j] + nums[k] < 0) ++j;
                else k--;
            }
            while(i < nums.length - 1 && nums[i] == nums[i+1]) ++i;
        }
        return ret;
    }
}