#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int cmp(vector<int>& a, vector<int>& b) {
    if (a[3] == b[3]) {
        if (a[0] == b[0]) {
            return a[4] < b[4];
        }
        return a[0] > b[0];
    }
    return a[3] > b[3];
}

int main() {
    int n; cin >> n;
    vector<vector<int>> scores = vector<vector<int>>(n, vector<int>(5, 0));
    for (int i = 0; i < n; ++i) {
        cin >> scores[i][0];
        cin >> scores[i][1];
        cin >> scores[i][2];
        scores[i][3] = scores[i][0] + scores[i][1] + scores[i][2];
        scores[i][4] = i+1;
    }
    sort(scores.begin(), scores.end(), cmp);
    for (int i = 0; i < 5; ++i) {
        cout << scores[i][4] << " " << scores[i][3] << endl;
    }
    return 0;
}
