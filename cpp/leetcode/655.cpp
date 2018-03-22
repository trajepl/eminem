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
    int height(TreeNode *root) {
        if(root == 0) return 0;
        return max(height(root->left), height(root->right)) + 1;         
    }
    
    void set_ret(int l, int r, int h, vector<vector<string>> &ret, 
                 TreeNode* node) {
        if(node == NULL) return;
        int mid = (l + r) / 2;
        ret[h][mid] = to_string(node->val);
        set_ret(l, mid-1, h+1, ret, node->left);
        set_ret(mid+1, r, h+1, ret, node->right);
    }
    
    vector<vector<string>> printTree(TreeNode* root) {
        int row = height(root);
        int col = (2 << row-1) - 1;
        vector<vector<string>> ret(row, vector<string>(col, ""));
        
        set_ret(0, col, 0, ret, root);
        
        return ret;
    }
};