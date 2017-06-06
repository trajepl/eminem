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

public class Solution {

    int helper(TreeNode root) {

        if(root == null) return 0;



        int leftHeight = helper(root.left);

        if(leftHeight == -1) return -1;

        int rightHeight = helper(root.right);

        if(rightHeight == -1) return -1;



        if(Math.abs(leftHeight - rightHeight) > 1) return -1;



        return Math.max(leftHeight, rightHeight)+1;

    }



    public boolean isBalanced(TreeNode root) {

        return helper(root) != -1;

    }

}
