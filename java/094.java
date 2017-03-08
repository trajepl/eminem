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
    List<Integer> ret = new ArrayList<>();
    public List<Integer> inorderTraversal(TreeNode root) {
        if(root == null) return ret;
        inorderTraversal(root.left);
        ret.add(root.val);
        inorderTraversal(root.right);
        return ret;
    }
}

public class Solution {
    public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer> ret = new ArrayList<>();
        if(root == null) return ret;
        Stack<TreeNode> s = new Stack<>();
        TreeNode p = root;

        while(s.isEmpty() || p != null) {
            if(p != null) {
                s.push(p);
                p = p.left;
            } else {
                p = s.pop();
                ret.add(p.val);
                if(p.right != null) {
                    s.push(p.right);
                    p = p.right.left;
                } else p = null;
            }
        }
        return ret;
    }
}
