#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int main() {
    int n; cin >> n;
    stack<pair<int, int>> s;
    vector<pair<int, int>> arr = vector<pair<int, int>>(n, make_pair(0, 0));
    for (int i = 0; i < n; ++i) {
        int t1, t2; cin >> t1 >> t2;
        arr[i] = make_pair(t1, t2);
    }
    sort(arr.begin(), arr.end());
    
    s.push(arr[0]);
    for (int i = 1; i < n; ++i) {
        pair<int, int> t = s.top();
        if (arr[i].first < t.second && arr[i].second > t.second) continue;
        if (arr[i].first < t.second && arr[i].second < t.second) {
            s.pop();
            s.push(arr[i]);
        } else if (arr[i].first >= t.second && arr[i].second > t.second) {
            s.push(arr[i]);
        }
    }
    cout << s.size() << endl;
    return 0;
}
