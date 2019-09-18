#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct dom {
    int x, y;
    int is_turn;
    int diff;

    dom (int x1, int y1, int is_turn1) {
        x = x1;
        y = y1;
        is_turn = x != y ? is_turn1 : 0;
        diff = (x - y) << 1;
    }
};

int main() {
    int n; cin >> n;
    vector<dom> arr(n+1, dom(0, 0, 0));
    int c = 0;
    int rls = 0;
    for (int i = 1; i <= n; ++i) {
        int a, b; cin >> a >> b;
        rls += a < b ? 1 : 0;
        arr[i] = a < b ? dom(b, a, -1) : dom(a, b, 1);
        c += abs(a-b);
    }

    vector<vector<int>> dp(n+1, vector<int>(c+1, 0));
    vector<vector<int>> vs(n+1, vector<int>(c+1, 0));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= c; ++j) {
            dp[i][j] = dp[i-1][j];
            vs[i][j] = vs[i-1][j];
            if ((j >= arr[i].diff && vs[i-1][j-arr[i].diff]) || j == arr[i].diff) {
                if (!vs[i][j]) {
                    dp[i][j] = dp[i-1][j-arr[i].diff] + arr[i].is_turn;
                    vs[i][j] = 1;
                } else {
                    dp[i][j] = min(dp[i][j], dp[i-1][j-arr[i].diff] + arr[i].is_turn);
                }
            }
        }
    }
    int rls_idx = 0;
    for (int i = c; i >= 1; --i) {
        if (vs[n][i] != 0) {
            rls_idx = i;
            break;
        }
    }
    cout << rls + dp[n][rls_idx] << endl;
    return 0;
}