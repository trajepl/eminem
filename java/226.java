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

    public TreeNode invertTree(TreeNode root) {

        if(root == null || (root.left == null && root.right == null)) return root;

        

        TreeNode tmp = null;

        tmp = root.left;

        root.left = root.right;

        root.right = tmp;

        

        root.left = invertTree(root.left);

        root.right = invertTree(root.right);

        

        return root;

    }

}
