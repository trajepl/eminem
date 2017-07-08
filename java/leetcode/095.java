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
    public List<TreeNode> generateTrees(int n) {
        if(n < 1) return new ArrayList<TreeNode>();
        return helper(1, n);
    }
    
    public List<TreeNode> helper(int start, int end) {
        List<TreeNode> res = new ArrayList<>();
        if(start > end) {
            res.add(null);
            return res;
        }
        
        for(int i = start; i <= end; i++) {
            List<TreeNode> leftList = helper(start, i - 1);
            List<TreeNode> rightList = helper(i + 1, end);
            
            for(TreeNode leftNode: leftList) {
                for(TreeNode rightNode: rightList) {
                    TreeNode head = new TreeNode(i);
                    head.left = leftNode;
                    head.right = rightNode;
                    res.add(head);
                }
            }
        }
        return res;
    }
}
