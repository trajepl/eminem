#include <iostream>

using namespace std;

int dp[100000] = {0};
int w[10001] = {0};
int v[10001] = {0};

int main() {
    int t, m; cin >> t >> m;
    for (int i = 1; i <= m; ++i) {
        cin >> w[i] >> v[i];
    }

    for (int i = 1; i <= m; ++i) {
        for (int j = t; j >= w[i]; --j) {
            dp[j] = max(dp[j], dp[j-w[i]] + v[i]);
        }
    }

    cout << dp[t] << endl;
    return 0;
}