/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */

/* 1 */
public class Solution {
    private List<Integer> ret = new ArrayList<>();
    public List<Integer> preorderTraversal(TreeNode root) {
        if(root == null) return ret;
        
        ret.add(root.val);
        preorderTraversal(root.left);
        preorderTraversal(root.right);
        return ret;
    }
}

/* 2 */
public class Solution {
    private List<Integer> ret = new ArrayList<>();

    public List<Integer> preorderTraversal(TreeNode root) {

        if(root == null) return ret;
        Stack<TreeNode> s = new Stack<>();
        s.push(root);

        while(!s.isEmpty()) {
            TreeNode tn = s.pop();
            ret.add(tn.val);
            if(tn.right != null) s.push(tn.right);
            if(tn.left != null) s.push(tn.left);
        }
        return ret;
    }
}
