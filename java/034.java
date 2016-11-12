/*Method 1*/
 public class Solution {
	 public int[] searchRange(int[] nums, int target) {
		 int l = 0, r = nums.length - 1;
		 int mid = 0;
		 boolean flag = false;

		 while(l <= r) {
			 mid = (l + r) / 2;
			 if(nums[mid] == target) {flag = true; break;}
			 if(target < nums[mid]) r = mid - 1;
			 else l = mid + 1;
		 }
		 if(!flag) return new int[]{-1, -1};

		 boolean lf = true, rf = true;
		 int lshift = mid, rshift = mid;
		 while(lf || rf) {
			 if(lf)
			 	 if(nums[lshift] == target) {
				 	 lshift --;
				 	 lf = lshift < 0 ? false : true;
				 } else lf = false;
			 if(rf)
				 if(nums[rshift] == target) {
	    	    	 rshift ++;
					 rf = rshift >= nums.length ? false : true;
				 } else rf = false;
		 }
		 return new int[]{lshift + 1, rshift - 1};
	 }
 }
/*Method 2*/
 public class Solution {
	 public int[] searchRange(int[] nums, int target) {
		 int lshift = lRang(nums, target);
		 int rshift = rRang(nums, target);
		 return new int[]{lshift, rshift};
	 }
	 
	 public int lRang(int[] nums, int target) {
	     int l = 0, r = nums.length - 1;
	     while(l <= r) {
	        int mid = (l + r) / 2;
	        if(nums[mid] < target) l = mid + 1;
	        else r = mid - 1;
	     }
	     if(l > nums.length-1 || nums[l] != target) return -1;
	     return l;
	 }
	 public int rRang(int[] nums, int target) {
	     int l = 0, r = nums.length - 1;
	     while(l <= r) {
	        int mid = (l + r) / 2;
	        if(nums[mid] > target) r = mid - 1;
	        else l = mid + 1;
	     }
	     if(r < 0 || nums[r] != target) return -1;
	     return r;
	 }
 }
