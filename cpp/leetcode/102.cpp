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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == NULL) return res;
        res.push_back({root->val});
        vector<TreeNode *> list = {root};
        while(list.size() != 0) {
            vector<int> vec;
            list = helper(list);
            if (list.size() == 0) break;
            for (auto it: list) {
                vec.push_back(it->val);
            }
            res.push_back(vec);
        }
        return res;
    }
    
    vector<TreeNode *> helper(vector<TreeNode *> level) {
        vector<TreeNode *> list;
        for(auto it : level) {
            if (it->left != NULL) list.push_back(it->left);
            if (it->right != NULL) list.push_back(it->right);
        }
        return list;
    }
};
