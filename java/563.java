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
    int ret = 0;
    
    public int findTilt(TreeNode root) {
        dfs(root);
        return ret;
    }
    
    private int dfs(TreeNode root) {
        if(root == null) return 0;
        
        int left = dfs(root.left);
        int right = dfs(root.right);
        
        ret += Math.abs(left - right);
        
        return root.val + left + right;
    }
}
