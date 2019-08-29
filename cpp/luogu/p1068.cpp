#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int cmp(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second) {
        return a.first < b.first;
    }
    return a.second > b.second;
}

int main() {
    int n, m; cin >> n >> m;
    vector<pair<int, int>> info = vector<pair<int, int>>(n, make_pair(0, 0));
    int bound = (int)(m * 1.5);
    for (int i = 0; i < n; ++i) {
        int f, s; cin >> f >> s;
        info[i] = make_pair(f, s);
    } 
    sort(info.begin(), info.end(), cmp);
    while (bound < n && info[bound].second == info[bound-1].second) {
        bound++;
    }
    cout << info[bound-1].second << " " << bound << endl;
    for (int i = 0; i < bound; ++i) {
        cout << info[i].first << " " << info[i].second << endl;
    }
    return 0;
}
