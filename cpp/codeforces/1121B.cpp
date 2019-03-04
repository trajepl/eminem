#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    int n;
    int ret = 0;
    cin >> n;
    vector<int> sweets = vector<int>(n, 0);
    unordered_map<int, int> dp = unordered_map<int,int>(); 
    for (int i = 0; i < n; ++i) cin >> sweets[i];
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int s = sweets[i] + sweets[j];
            if (dp.find(s) == dp.end()) {
                dp.insert(make_pair(s, 1));
            } else dp[s] = dp[s] + 1;
            if (dp[s] > ret) ret = dp[s];
        }
    }
    cout << ret << endl;
    return 0;
}
