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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty()) return NULL;
        int head_val = preorder.front();
        TreeNode* root = new TreeNode(head_val);
        
        int head_idx = 0;
        for (int i = 0; i < inorder.size(); ++i) {
            if (inorder[i] == head_val) {
                head_idx = i;
                break;
            }
        }
        vector<int> left_p = vector<int>(preorder.begin() + 1, preorder.begin() + 1 + head_idx);
        vector<int> left_i = vector<int>(inorder.begin(), inorder.begin() + head_idx);
        vector<int> right_p = vector<int>(preorder.begin() + 1 + head_idx, preorder.end());
        vector<int> right_i = vector<int>(inorder.begin() + head_idx + 1, inorder.end());
        root->left = buildTree(left_p, left_i);
        root->right = buildTree(right_p, right_i);
        return root;
    }
};
