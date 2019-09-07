#include <iostream>

using namespace std;

int dp[20001] = {0};
int w[31];


int main() {
    int c, m; cin >> c >> m;
    for (int i = 1; i <= m; ++i) {
        cin >> w[i];
    }

    for (int i = 1; i <= m; ++i) {
        for (int j = c; j >= w[i]; --j) {
            dp[j] = max(dp[j], dp[j-w[i]] + w[i]);
        }
    }

    cout << c - dp[c] << endl;
    return 0;
}