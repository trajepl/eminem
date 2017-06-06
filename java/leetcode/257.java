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

    public List<String> binaryTreePaths(TreeNode root) {

        List<String> res = new ArrayList<>();

        dfs(root, new String(), res);

        return res;

    }

    

    private void dfs(TreeNode root, String s, List<String>res) {

        if(root == null) return ;

        if(root.left == null && root.right == null) {

            res.add(s+root.val);

            return ;

        }

        if(root.left != null) dfs(root.left, s + root.val + "->", res);

        if(root.right != null) dfs(root.right, s + root.val + "->", res);

    }

}
