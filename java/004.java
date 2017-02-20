// Method1: (not better than Method2)

public class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int len1 = nums1.length;
        int len2 = nums2.length;
        int total = len1 + len2;
        if(total % 2==0){
            return (findKth(nums1,nums2,total/2)+findKth(nums1,nums2,total/2+1))/2.0;
        } else {
            return findKth(nums1,nums2,total/2+1);
        }
    }
    private int findKth(int[] nums1, int[] nums2, int k){
        int p = 0, q = 0;
        for(int i = 0; i < k - 1; i++){
            if(p>=nums1.length && q<nums2.length){
                q++;
            } else if(q>=nums2.length && p<nums1.length){
                p++;
            } else if(nums1[p]>nums2[q]){
                q++;
            } else {
                p++;
            }
        }
        if(p>=nums1.length) {
            return nums2[q];
        } else if(q>=nums2.length) {
            return nums1[p];
        } else {
            return Math.min(nums1[p],nums2[q]);
        }
    }
}

// Method2: O(log(m+n))

public class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int len1 = nums1.length, len2 = nums2.length;
        int k = (len1 + len2) / 2;
        
        if((len1 + len2) %2 == 0)
            return (Kth(nums1, nums2, 0, 0, len1, len2, k) + Kth(nums1, nums2, 0, 0, len1, len2, k + 1)) / 2;
        else 
            return Kth(nums1, nums2, 0, 0, len1, len2, k+1);
    }
    
    public double Kth(int[] a, int[] b, int start1, int start2, int len1, int len2, int k) {
        if(len1 > len2) 
            return Kth(b, a, start2, start1, len2, len1, k);
        if(len1 == 0) 
            return b[start2 + k - 1];
        if(k == 1) 
            return Math.min(a[start1], b[start2]);
        int m = Math.min(k / 2, len1);
        int n = k - m;
        if(a[start1 + m - 1] < b[start2 + n - 1])
            return Kth(a, b, start1 + m, start2, len1 - m, len2, k - m);
        else if(a[start1 + m - 1] > b[start2 + n - 1]) 
            return Kth(a, b, start1, start2 + n, len1, len2 - n, k - n);
        else
            return a[start1 + m - 1];
            
    }
}
