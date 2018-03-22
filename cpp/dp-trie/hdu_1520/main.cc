#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dfs(int node, vector<vector<int>> &tree, vector<vector<int>> &dp, vector<bool> &vis) {
    vis[node] = true;
    int n = tree[node].size();
    for(int i = 0; i < n; i++) {
        if(tree[node][i] == 0 || vis[i]) continue;
        vis[i] = true;
        dfs(i, tree, dp, vis);
        dp[node][0] += max(dp[i][1], dp[i][0]);
        dp[node][1] += dp[i][0];
    }
}

int main() {
    int n; cin >> n;
    int len = n;
    vector<vector<int>> dp(len, vector<int>(2, 0));
    int j = 0;
    while (n-- > 0) {
        int num; cin >> num;
        dp[j++][1] = num;
    }

    vector<vector<int>> tree(len, vector<int>(len, 0));
    vector<bool> is_root(len, true);
    while(true) {
        int a, b;
        cin >> a >> b;
        if(a == 0 && b == 0) break;
        tree[b-1][a-1] = 1;
        is_root[a-1] = false;
    }

    int ret = 0;
    vector<bool> vis(len, false);
    for(int i = 0; i < len; i++) {
        if(!is_root[i]) continue;
        dfs(i,tree, dp, vis);
        ret =  max(dp[i][0], dp[i][1]);
    }
    cout << ret << endl;
    return 0;
}
