#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool flipEquiv(TreeNode* root1, TreeNode* root2) {
    if (root1 == root2) return true;
    else if (root1 == NULL || root2 == NULL) return false;
    else if (root1->val != root2->val) return false;
    queue<TreeNode*> q1, q2;
    q1.push(root1); q2.push(root2);
    while (!q1.empty() && !q2.empty()) {
        TreeNode *node1 = q1.front(); q1.pop();
        TreeNode *node2 = q2.front(); q2.pop();
        if (node1 == NULL || node2 == NULL) continue;
        if (node1->val != node2->val) return false;
        if (node1->left == NULL) {
            if (node2->left == NULL) {
                if (node1->right != NULL && node2->right != NULL) {
                    q1.push(node1->right); q2.push(node2->right);
                } else if (node1->right == NULL && node2->right == NULL) {
                    continue;
                } else return false;
            } else if (node2->right == NULL) {
                if (node1->right != NULL && node2->left != NULL) {
                    q1.push(node1->right); q2.push(node2->left);
                } else if (node1->right == NULL && node2->left == NULL) {
                    continue;
                } else return false;
            } else return false;
        } else if (node1->right == NULL) {
            if (node2->right == NULL) {
                if (node1->left != NULL && node2->left != NULL) {
                    q1.push(node1->left); q2.push(node2->left);
                } else if (node1->left == NULL && node2->left == NULL) {
                    continue;
                } else return false;
            } else if (node2->left == NULL) {
                 if (node1->left != NULL && node2->right != NULL) {
                    q1.push(node1->left); q2.push(node2->right);
                } else if (node1->left == NULL && node2->right == NULL) {
                    continue;
                } else return false;
            } else return false;
        } else if (node2->left == NULL || node2->right == NULL) {
            return false;
        } else if (node1->left->val == node2->left->val &&
                node1->right->val == node2->right->val) {
            q1.push(node1->left); q1.push(node1->right);
            q2.push(node2->left); q2.push(node2->right);
        } else if (node1->left->val == node2->right->val &&
                node1->right->val == node2->left->val) {
            q1.push(node1->left); q1.push(node1->right);
            q2.push(node2->right); q2.push(node2->left);
        } else {
            cout << 6 << endl;
            return false;
        }
    }
    return true;
}
