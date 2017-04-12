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
    public int sumOfLeftLeaves(TreeNode root) {
        if(root == null) return 0;
        int ret = 0;
        ret += dfs_left(root.left, true);
        ret += dfs_left(root.right, false);
        return ret;
    }

    int dfs_left(TreeNode root, boolean is_left) {
        if(root == null) return 0;
        if(root.left == null && root.right == null && is_left) return root.val;
        return dfs_left(root.left, true) + dfs_left(root.right, false);
    }
}

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
    public int sumOfLeftLeaves(TreeNode root) {
        if(root == null) return 0;
        int ret = 0;
        Stack<TreeNode> left_s = new Stack<>();
        left_s.push(root);
        
        while(!left_s.empty()) {
            TreeNode node = left_s.pop();
            if(node.left != null) {
                if(node.left.left == null && node.left.right == null) ret += node.left.val;
                else left_s.push(node.left);
            }
            if(node.right != null) {
                if(node.right.left != null || node.right.right != null) left_s.push(node.right);
            }
        
        }
      return ret;
    }
}
