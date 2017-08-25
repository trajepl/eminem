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
    public TreeNode deleteNode(TreeNode root, int key) {
        if(root == null) return null;
        if(key < root.val) root.left = deleteNode(root.left, key);
        else if(key > root.val) root.right = deleteNode(root.right, key);
        else {
            if(root.left == null && root.right == null) root = null;
            else if(root.left == null) root = root.right;
            else if(root.right == null) root = root.left;
            else {
                TreeNode node = root.left;
                while(node.right != null && node.right.right != null)
                    node = node.right;
                
                if(node.right == null) {
                    node.right = root.right;
                    root = node;
                } else {
                    node.right.right = root.right;
                    TreeNode leftTmp = node.right.left;
                    node.right.left = root.left;
                    root = node.right;
                    
                    node.right = leftTmp;
                }
            }
        }
        
        return root;
    }
}
