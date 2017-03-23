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

    int depth (TreeNode root) {

        if (root == null) return 0;

        return Math.max(depth(root.left), depth (root.right)) + 1;

    }



    public boolean isBalanced (TreeNode root) {

        if (root == null) return true;

        

        int left=depth(root.left);

        int right=depth(root.right);

        

        return Math.abs(left - right) <= 1 && isBalanced(root.left) && isBalanced(root.right);
    }
}
