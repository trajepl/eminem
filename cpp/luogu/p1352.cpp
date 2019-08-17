#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void tree_dp(vector<vector<int>>&dp, vector<vector<int>>& graph,\
        vector<int>& val, int i) {
    dp[i][0] = 0;
    dp[i][1] = val[i];
    int len = graph[i].size();
    for (int j = 0; j < len; ++j) {
        int son = graph[i][j];
        tree_dp(dp, graph, val, graph[i][j]);
        dp[i][0] += max(dp[son][1], dp[son][0]);
        dp[i][1] += dp[son][0]; 
    }
}

int main() {
    int n; cin >> n;
    vector<int> val = vector<int>(n+1, 0);
    for (int i = 1; i < n+1; ++i) {
        cin >> val[i];
    }
    vector<int> ind = vector<int>(n+1, 0);
    vector<vector<int>> graph = vector<vector<int>>(n+1, vector<int>());
    int a, b;
    while (cin >> a >> b) {
        if (a == 0 && b == 0) break;
        graph[b].push_back(a); 
        ind[a] = 1;
    }
    for (int i = 1; i <= n; ++i) {
        if (!ind[i]) {
            graph[0].push_back(i);
        }
    }
    vector<vector<int>> dp = vector<vector<int>>(n+1, vector<int>(2, 0));
    tree_dp(dp, graph, val, 0);
    cout << dp[0][0] << endl;
    return 0;
}
