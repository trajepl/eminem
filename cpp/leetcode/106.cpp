#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    if (inorder.empty()) return NULL;
    int head_val = postorder.back();
    TreeNode* root = new TreeNode(head_val);
    if (inorder.size() <= 1) return root;

    int head_idx = 0;
    for (int i = 0; i < inorder.size(); ++i) {
        if (inorder[i] == head_val) {
            head_idx = i;
            break;
        }
    }

    vector<int> left_i = vector<int>(inorder.begin(), inorder.begin() + head_idx);
    vector<int> left_p = vector<int>(postorder.begin(), postorder.begin() + head_idx);
    vector<int> right_i = vector<int>(inorder.begin() + head_idx + 1, inorder.end());
    vector<int> right_p = vector<int>(postorder.begin() + head_idx, postorder.end() - 1);
    root->left = buildTree(left_i, left_p);
    root->right = buildTree(right_i, right_p);
    return root;
}
int main() {
    vector<int> inorder = {9,3,15,20,7};
    vector<int> postorder = {9,15,7,20,3};
    TreeNode* root = buildTree(inorder, postorder);
    return 0;
}
