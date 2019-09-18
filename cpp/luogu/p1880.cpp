#include <iostream>
#include <cstring>

using namespace std;

int stones[200];
int dp_max[200][200];
int dp_min[200][200];
int prefix_sum[201];

int main() {
    int n; cin >> n;
    memset(stones, 0, sizeof(stones));
    memset(prefix_sum, 0, sizeof(prefix_sum));
    memset(dp_max, 0, sizeof(dp_max));
    memset(dp_min, 0x3f, sizeof(dp_min));

    for (int i = 0; i < n; ++i) {
        cin >> stones[i];
        stones[i+n] = stones[i];
        dp_max[i][i] = stones[i];
        dp_max[i+n][i+n] = stones[i];
        dp_min[i][i] = stones[i];
        dp_min[i+n][i+n] = stones[i];
    }
    for (int i = 0; i < (n << 1); ++i) {
        prefix_sum[i+1] = prefix_sum[i] + stones[i];
    }

    n = n << 1;
    for (int d = 1; d < (n >> 1); ++d) {
        for (int i = 0, j = i+d; i < n && j < n; ++i, j = i+d) {
            for (int k = i; k < j; ++k) {
                int ldiff = prefix_sum[k+1] - prefix_sum[i];
                int rdiff = prefix_sum[j+1] - prefix_sum[k+1];
                if (i == k) {
                    ldiff = 0;
                }
                if (k+1 == j) {
                    rdiff = 0;
                }
                dp_max[i][j] = max(dp_max[i][k] + dp_max[k+1][j] + ldiff + rdiff, dp_max[i][j]);
                dp_min[i][j] = min(dp_min[i][k] + dp_min[k+1][j] + ldiff + rdiff, dp_min[i][j]);
            }
        }
    }
    int rls_max = 0, rls_min = 1e+9;
    for (int i = 0, j = i + (n >> 1) - 1; i < n; ++i, j = i + (n >> 1) - 1) {
        rls_max = max(rls_max, dp_max[i][j]);
        rls_min = min(rls_min, dp_min[i][j]);
    }
    cout << rls_min << endl;
    cout << rls_max << endl;
    return 0;
}