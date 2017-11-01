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
    public TreeNode convertBST(TreeNode root) {
        Stack<TreeNode> stack = new Stack<>();
        TreeNode head = root;
        int sum = 0;
        while(head != null || !stack.isEmpty()) {
            if(head != null) {
                stack.push(head);
                head = head.right;
            } else {
                TreeNode node = stack.pop();
                System.out.println(node.val);
                sum += node.val;
                node.val = sum;
                head = node.left;
            }
        }
        
        return root;
    }
}

public class Solution {

    int sum = 0;

    public TreeNode convertBST(TreeNode root) {
        convert(root);
        return root;
    }

    public void convert(TreeNode cur) {
        if (cur == null) return;
        convert(cur.right);
        cur.val += sum;
        sum = cur.val;
        convert(cur.left);
    }

}
