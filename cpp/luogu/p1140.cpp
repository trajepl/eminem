#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

#define inf 1000000000

using namespace std;

int main() {
    int n; cin >> n;
    string a; cin >> a;
    int m; cin >> m;
    string b; cin >> b;
    a = " " + a;
    b = " " + b;
    vector<vector<int>> scores = {
        {0, 0, 0, 0, 0, 0},
        {0, 5, -1, -2, -1, -3},
        {0, -1, 5, -3, -2, -4},
        {0, -2, -3, 5, -2, -2},
        {0, -1, -2, -2, 5, -1},
        {0, -3, -4, -2, -1, -inf}
    };
    unordered_map<char, int> map;
    map['A'] = 1;
    map['C'] = 2;
    map['G'] = 3;
    map['T'] = 4;
    map['-'] = 5;

    vector<vector<int>> dp(n+1, vector<int>(m+1, -inf));
    dp[0][0] = 0;
    for (int i = 1; i <= n; ++i) {
        dp[i][0] = dp[i-1][0] + scores[map[a[i]]][map['-']];
    }
    for (int j = 0; j <= m; ++j) {
        dp[0][j] = dp[0][j-1] + scores[map['-']][map[b[j]]];
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            dp[i][j] = max(dp[i][j], dp[i-1][j] + scores[map[a[i]]][map['-']]);
            dp[i][j] = max(dp[i][j], dp[i][j-1] + scores[map['-']][map[b[j]]]);
            dp[i][j] = max(dp[i][j], dp[i-1][j-1] + scores[map[a[i]]][map[b[j]]]);
        }
    }
    cout << dp[n][m] << endl;
    return 0;
}