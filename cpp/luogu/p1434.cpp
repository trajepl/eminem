#include <iostream>
#include <cstring>

using namespace std;

int r, c;
int dp[100][100];
int mat[100][100];
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int dfs(int i, int j, int pre) {
    if (i < 0 || i >= r || j < 0 || j >= c) return 0;
    if (dp[i][j] > 0 && mat[i][j] < pre) return dp[i][j];
    if (mat[i][j] >= pre) return 0;

    int rls = 0;
    for (const auto& item: dir) {
        int t = 1 + dfs(i + item[0], j + item[1], mat[i][j]);
        rls = max(rls, t);
    }
    return dp[i][j] = rls;
}

int main() {
    cin >> r >> c;
    memset(dp, 0, sizeof(dp));
    memset(mat, 0, sizeof(mat));
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cin >> mat[i][j];
        }
    }
    
    int rls = 0;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            dfs(i, j, 1e9);
            rls = max(rls, dp[i][j]);
        }
    }
    cout << rls << endl;
    return 0;
}