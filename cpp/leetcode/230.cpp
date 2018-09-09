#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}; 

TreeNode *build(vector<int> &vec) {
    queue<TreeNode *> q;
    TreeNode *root = new TreeNode(vec[0]);
    q.push(root);
    
    for (int i = 1; i< vec.size(); i += 2) {
        TreeNode *p = q.front(); q.pop();
        if (vec[i] != 0) 
            p->left = new TreeNode(vec[i]);
        if (vec[i+1] != 0)
            p->right = new TreeNode(vec[i+1]);

        q.push(p->left); q.push(p->right);
    }
    return root;
}


class Solution {
public:
    int kthSmallest(TreeNode *root, int k) {
        stack<TreeNode *> s;
        TreeNode *p = root;
        s.push(p);
        while (!s.empty()) {
            if (p != NULL) {
                s.push(p);
                p = p->left;
            } else {
                p = s.top();
                s.pop();

                k--;
                if (k == 0) return p->val;
                
                p = p->right;;
            }
        }   
    }
};

int main() {
    vector<int> vec = {3};
    TreeNode *root = build(vec);

    
    Solution sol = Solution();
    cout << sol.kthSmallest(root, 1) << endl;
    return 0;
}
