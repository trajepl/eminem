#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int n; cin >> n;
    vector<int> arr = vector<int>(n, 0);
    for (int i  = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int rls1 = 1;
    vector<int> dp1 = vector<int>(n, 1);
    vector<int> d1 = vector<int>(n, 0);
    d1[0] = arr[0];
    for (int i = 1; i < n; ++i) {
        if (arr[i] > d1[rls1-1]) {
            d1[rls1++] = arr[i];
            dp1[i] = rls1;
        } else {
            auto it = lower_bound(d1.begin(), d1.begin() + rls1, arr[i]);
            *it = arr[i];
            dp1[i] = it - d1.begin() + 1;
        }
    }

    int rls2 = 1;
    vector<int> dp2 = vector<int>(n, 1);
    vector<int> d2 = vector<int>(n, 0);
    d2[0] = arr[n-1];
    for (int i = n-2; i > -1; --i) {
        if (arr[i] > d2[rls2-1]) {
            d2[rls2++] = arr[i];
            dp2[i] = rls2;
        } else {
            auto it = lower_bound(d2.begin(), d2.begin() + rls2, arr[i]);
            *it = arr[i];
            dp2[i] = it - d2.begin() + 1;
        }
    }

    int rls = 0;
    int rls_i = 0;
    for (int i = 0; i < n; ++i) {
        int max_t = dp1[i] + dp2[i];
        if (max_t > rls) {
            rls_i = i;
            rls = max_t;
        }
    }
    cout << n - rls + 1 << endl;
    return 0;
}