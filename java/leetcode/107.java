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

    public List<List<Integer>> levelOrderBottom(TreeNode root) {

        List<List<Integer>> res = new LinkedList<>();

        if(root == null) return res;

        

        Queue<TreeNode> level = new LinkedList<>();

        level.offer(root);

        

        while(!level.isEmpty()) {

            int n = level.size();

            List<Integer> tmp = new ArrayList<>();

            for(int i = 0; i < n; i++) {

                TreeNode node = level.poll();

                tmp.add(node.val);

                

                if(node.left != null) level.offer(node.left);

                if(node.right != null) level.offer(node.right);

            }

            res.add(0, new ArrayList<>(tmp));

        }

        return res;

    }

}
