#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    int n; cin >> n;
    vector<pair<int, int>> arr = vector<pair<int, int>>(n, make_pair(0, 0));
    for (int i = 0; i < n; ++i) {
        int t; cin >> t;
        arr[i] = make_pair(t, i+1);
    }
    double sum_res = 0;
    sort(arr.begin(), arr.end());
    int i = 0;
    for (const auto& it: arr) {
        cout << it.second << " ";
        sum_res += it.first * (n-i-1);
        i++;
    }
    cout << endl << setiosflags(ios::fixed) << setprecision(2) << sum_res/n << endl;
    return 0;
}
