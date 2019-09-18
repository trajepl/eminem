#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k; cin >> n >> k;
    vector<pair<int, int>> tasks = vector<pair<int, int>>(k+1, make_pair(0, 0));
    for (int i = 1; i <= k; ++i)  {
        cin >> tasks[i].first >> tasks[i].second;
    }
    sort(tasks.begin(), tasks.end(), 
        [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.first < b.first;
        }
    );

    vector<int> dp = vector<int>(n+2, 0);
    for (int i = n, j = k; i >= 1; --i) {
        while (j >= 1 && tasks[j].first > i) j--;
        if (j >= 1 && tasks[j].first == i) {
            while (j >= 1 && tasks[j].first == i) {
                dp[i] = max(dp[i], dp[i + tasks[j].second]);
                --j;
            }
        } else {
            dp[i] = dp[i+1] + 1;
        }
    }
    cout << dp[1] << endl;
    return 0;
}