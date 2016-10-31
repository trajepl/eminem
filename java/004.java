Method1:

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

Method2:
