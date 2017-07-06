// 68ms
public class Solution {
    public int findUnsortedSubarray(int[] nums) {
        Queue<Integer> minHeap = new PriorityQueue<>();
        Queue<Integer> maxHeap = new PriorityQueue<>(new Comparator<Integer>() {
            public int compare(Integer e1, Integer e2) {
				return e2 - e1;
			}
        });
        
        for(int i: nums) {
            minHeap.offer(i);
            maxHeap.offer(i);
        }
        int left = 0, right = nums.length-1;
        
        while(left < nums.length && minHeap.poll() == nums[left]) left++;
        if(left == nums.length) return 0;
        while(right >= 0 && maxHeap.poll() == nums[right]) right--;
        
        return right - left + 1;
    }
}

// 27ms
public class Solution {
    public int findUnsortedSubarray(int[] A) {
        int n = A.length, beg = -1, end = -2, min = A[n-1], max = A[0];
        for (int i=1;i<n;i++) {
          max = Math.max(max, A[i]);
          min = Math.min(min, A[n-1-i]);
          if (A[i] < max) end = i;
          if (A[n-1-i] > min) beg = n-1-i; 
        }
        return end - beg + 1;
    }
}
