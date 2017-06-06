/**

 * Definition for a binary tree node.

 * public class TreeNode {

 *     int val;

 *     TreeNode left;

 *     TreeNode right;

 *     TreeNode(int x) { val = x; }

 * }

 */

public class Solution {

    public TreeNode sortedArrayToBST(int[] nums) {

        if(nums.length == 0) return null;

        

        int mid = (nums.length-1) / 2;

        TreeNode root = new TreeNode(nums[mid]); 

        TreeNode tmp = root;

        

        root.left = sortedArrayToBST(Arrays.copyOfRange(nums, 0, mid));

        root.right = sortedArrayToBST(Arrays.copyOfRange(nums, mid+1, nums.length));

        return root;

    }

}
