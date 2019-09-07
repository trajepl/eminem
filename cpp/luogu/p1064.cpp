#include <iostream>

using namespace std;

int dp[32000];
unsigned long long int mem[32000] = {0};
int w[60], v[60], p[60];

int main() {
    int n, m; cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        cin >> w[i] >> v[i] >> p[i];
        v[i] *= w[i];
    }

    for (int i = 1; i <= m; ++i) {
        for (int j = n; j >= w[i]; --j) {
            if (p[i] > 0) {
                int h = mem[j];
                if ((h >> p[i]) & 1) {
                    if (dp[j] <= dp[j-w[i]] + v[i]) {
                        if ((mem[j-w[i]] >> p[i]) & 1) {
                            dp[j] = dp[j-w[i]] + v[i];
                            mem[j] = mem[j-w[i]] | (1 << i);
                        } else {
                            if (j >= w[i]+w[p[i]] && dp[j] <= dp[j-w[i]-w[p[i]]] + v[i] + v[p[i]]) {
                                dp[j] = dp[j-w[i]-w[p[i]]] + v[i] + v[p[i]];
                                mem[j] = mem[j-w[i]-w[p[i]]] | (1 << i);
                                mem[j] = mem[j-w[i]-w[p[i]]] | (1 << p[i]);
                            }
                        }
                    }
                } else {
                    if (j >= w[i]+w[p[i]] && dp[j] <= dp[j-w[i]-w[p[i]]] + v[i] + v[p[i]]) {
                        dp[j] = dp[j-w[i]-w[p[i]]] + v[i] + v[p[i]];
                        mem[j] = mem[j-w[i]-w[p[i]]] | (1 << i);
                        mem[j] = mem[j-w[i]-w[p[i]]] | (1 << p[i]);
                    }
                }
            } else {
                if (dp[j] <= dp[j-w[i]] + v[i]) {
                    dp[j] = dp[j-w[i]] + v[i];
                    mem[j] = mem[j-w[i]] | (1 << i);
                }
            }
        }
    }
    cout << dp[n] << endl;
    return 0;
}