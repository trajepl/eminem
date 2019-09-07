#include <iostream>

using namespace std;

int dp[10000] = {0};
int foods[101];

int main() {
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> foods[i];
    }

    dp[0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = m; j >= foods[i]; --j) {
            dp[j] = dp[j] + dp[j-foods[i]];
        }
    }

    cout << dp[m] << endl;
    return 0;
}