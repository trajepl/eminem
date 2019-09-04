#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int total, n; cin >> total >> n;
    vector<pair<int, int>> milks = vector<pair<int, int>>(n, make_pair(0, 0));
    for (int i = 0; i < n; ++i) {
        int t1, t2; cin >> t1 >> t2;
        milks[i] = make_pair(t1, t2);
    }
    sort(milks.begin(), milks.end());
    
    int res = 0;
    for (const auto& it: milks) {
        if (total <= 0) break;
        if (total > it.second) {
            res += it.first * it.second;
            total -= it.second;
        } else {
            res += it.first * total;
            total = 0;
        }
    }
    cout << res << endl; 
    return 0;
}
