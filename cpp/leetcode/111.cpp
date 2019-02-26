/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        if (root->left == nullptr && root->right == nullptr) return 0;
        
        int leftMinDepth = INT_MAX, rightMinDepth = INT_MAX;
        if (root->left != nullptr)
            leftMinDepth = 1 + minDepth(root->left);
        if (root->right != nullptr)
            rightMinDepth = 1 + minDepth(root->right);
        return min(leftMinDepth, rightMinDepth);
    }
};
