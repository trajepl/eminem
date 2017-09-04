/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public void flatten(TreeNode root) {
        Stack<TreeNode> s = new Stack<>();
        s.push(null);
        TreeNode p = root;
    
        while(p != null) {
            if(p.left != null) {
                if(p.right != null)
                    s.push(p.right);
                p.right = p.left;
                p.left = null;
                p = p.right;
            } else if(p.right != null) {
                p = p.right;
            } else {
                p.right = s.pop();
                p = p.right;
            }
        }
    }
}

class Solution {
    TreeNode pre;
    
    public void flatten(TreeNode root) {
        if(root == null)
            return;
        
        if(pre != null) {
            pre.right = root;
            pre.left = null;
        }
        
        TreeNode right = root.right;
        pre = root;
        flatten(root.left);
        flatten(right);
    }
}
