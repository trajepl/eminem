public class Solution {
    public int findKthLargest(int[] nums, int k) {
        int left = 0, right = nums.length-1;
        while(left < right) {
            int pos = partition(nums, left, right);
            if(pos > k-1) right = pos - 1;
            else if(pos < k-1) left = pos + 1;
            else break;
        }
        return nums[k-1];
    }
    
    public int partition(int[] nums, int left, int right) {
        Random rand = new Random();
        int point =  rand.nextInt(right - left + 1) + left;
        swap(nums, left, point);

        int flag = left;
        for(int i = left + 1; i <= right; i++) {
            if(nums[i] > nums[left])
                swap(nums, ++flag, i);
        }
        swap(nums, left, flag);
        
        return flag;
    }
    
    public void swap(int[] a, int i, int j) {
        int tmp = a[i]; a[i] = a[j]; a[j] = tmp;
    }
}
