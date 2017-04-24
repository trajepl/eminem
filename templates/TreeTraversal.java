public class TreeTraversal {
    class TreeNode {
        TreeNode left;
        TreeNode right;
        int val;
        TreeNode(int val) {this.val = val;}
    }
    

    public List<Integer> preOrder(TreeNode root) {
        List<Integer> ret = new ArrayList<>();
        Stack<TreeNode> stack = new Stack<>();
        TreeNode head = root;

        while(!stack.isEmpty() || p != null) {
            if(p != null) {
                stack.push(p);
                ret.add(p.val);    // add to List before go to children
                p = p.left;
            } else {
                TreeNode node = stack.pop();
                p = node.right;
            }
        }

        return ret;
    }

    public List<Integer> inOrder(TreeNode root) {
        List<Integer> ret = new ArrayList<>();
        Stack<TreeNode> stack = new Stack<>();
        TreeNode p = root;

        while(!stack.isEmpty() || p != null) {
            if(p != null) {
                stack.push(p);
                p = p.left;
            } else {
                TreeNode node = stack.pop();
                ret.add(node.val);
                p = node.right;
            }
        }
        return ret;
    }

    public List<Integer> posterOrder(TreeNode root) {
        List<Integer> ret = new ArrayList<>();
        Stack<TreeNode> stack = new Stack<>();
        TreeNode p = root;

        while(!stack.isEmpty() || p != null) {
            if(p != null) {
                stack.push(p);
                ret.add(p.val);
                p = p.right;
            } else {
                TreeNode node = stack.peek();
                p = node.left;
            }
        }

        Collections.reverse(ret);

        return ret;
    }

    public List<Integer> posterOrder(TreeNode root) {
        List<Integer> ret = new ArrayList<>();
        Stack<TreeNode> stack = new Stack<>();
        TreeNode p = root;
        TreeNode cur = null;

        while(p != null || !stack.isEmpty()) {
            while(p != null) {
                stack.add(p);
                   p = p.left;
            }

            p = stack.peek();

            if(p.right != null && cur != p.right) 
                p = p.right;
            else
                stack.pop();
                ret.add(p.val);
                cur = p;
                p = null;
        }
        return ret;
    }
}


















