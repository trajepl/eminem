#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

int dp[30000] = {0};
int arr[30][2];
 
int main() {
    int n, m; cin >> n >> m;
    memset(dp, 0, sizeof(dp)); 
    for (int i = 1; i <= m; ++i) {
        cin >> arr[i][0] >> arr[i][1];
        arr[i][1] *= arr[i][0];
    }

    for (int i = 1; i <= m; ++i) {
        for (int j = n; j >= 0; --j) {
            if (j >= arr[i][0])
                dp[j] = max(dp[j], dp[j-arr[i][0]] + arr[i][1]);
        }
    }

    cout << dp[n] << endl;
    return 0;
}