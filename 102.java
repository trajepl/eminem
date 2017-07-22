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
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> ret = new ArrayList<>();
        Queue<TreeNode> queue = new LinkedList<>();
        
        queue.offer(root);
    
        while(!queue.isEmpty()) {
            int len = queue.size();
            List<Integer> subList = new ArrayList<>();
            for(int i = 0; i < len; i++) {
                TreeNode node = queue.poll();   
                if(node != null) {
                    queue.offer(node.left);
                    queue.offer(node.right);
                    subList.add(node.val);
                }
            }
            if(subList.size() > 0)
                ret.add(subList);
        }
        return ret;
    }
}
