/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func findBottomLeftValue(root *TreeNode) int {
    ret, _ := dfs(root, 0, -1, 0)
    return ret
}

func dfs(root *TreeNode, deep int, flagDeep int, ret int) (int, int) {
    if root == nil {
        return ret, flagDeep
    }
    if root.Left == nil && root.Right == nil {
        if deep > flagDeep {
            ret = root.Val
            flagDeep = deep
        }
    }
    ret, flagDeep = dfs(root.Left, deep + 1, flagDeep, ret)
    ret, flagDeep = dfs(root.Right, deep + 1, flagDeep, ret)
    return ret, flagDeep
}
