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

    public List<Integer> postorderTraversal(TreeNode root) {
        if(root == null) return ret;
        postorderTraversal(root.left);
        postorderTraversal(root.right);
        ret.add(root.val);
        return ret;
    }
}

public class Solution {
    public List<Integer> postorderTraversal(TreeNode root) {
        List<Integer> ret = new ArrayList<>();
        if(root == null) return ret;
        Stack<TreeNode> s = new Stack<>();

        TreeNode p = root, r = null;
        while(p != null || !s.isEmpty()) {
            if(p != null) {
                s.push(p);
                p = p.left;
            } else if(p.right != null && p.right != r){
                p = p.right;
                s.push(p);
                p = p.left();
            } else {
                p = s.pop();
                ret.add(p.val);
                r = p;
                p = null;
            }
        }
        return ret;
    }
}

