

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

    // public int maxDepth(TreeNode root) {

    //     if(root == null) return 0;

    //     return 1+Math.max(maxDepth(root.left), maxDepth(root.right));

    // }

    

    public int maxDepth(TreeNode root) {

        if(root == null) return 0;

        

        Queue<TreeNode> level = new LinkedList<>();

        level.offer(root);

        int sum = 0;

        

        while(!level.isEmpty()) {

            sum++;

            int len = level.size();

            for(int i = 0; i < len; i++) {

                TreeNode node = level.poll();

                if(node.left != null) level.offer(node.left);

                if(node.right != null) level.offer(node.right);

            }

        }

        return sum;

    }

}
