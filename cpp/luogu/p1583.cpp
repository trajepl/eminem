#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <unordered_map>

using namespace std;

int cmp(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first) {
        return a.second < b.second;
    }
    return a.first > b.first;
}

int main() {
    int n, k; cin >> n >> k;
    vector<int> e = vector<int>(10, 0);
    for (int i = 0; i < 10; ++i) {
        cin >> e[i];
    }
    vector<pair<int, int>> arr = vector<pair<int, int>>(n, make_pair(0, 0));
    for (int i = 0; i < n; ++i) {
        cin >> arr[i].first;
        arr[i].second = i+1;
    }
    sort(arr.begin(), arr.end(), cmp);
    for (int i = 0; i < n; ++i) {
        arr[i].first += e[i%10];
    }
    sort(arr.begin(), arr.end(), cmp);
    for (int i = 0; i < k; ++i) {
        cout << arr[i].second << " ";
    }
    cout << endl;
    return 0;
}
