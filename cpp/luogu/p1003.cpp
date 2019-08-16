#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n; cin >> n;
    vector<vector<int>> cords = vector<vector<int>>(n, vector<int>(4, 0));
    for (int i = 0; i < n; ++i) {
        int x1, y1, a, b;
        cin >> x1 >> y1 >> a >> b;
        cords[i] = vector<int>{x1, y1, x1+a, y1+b};
    }

    int x, y;
    cin >> x >> y;
    int res = -2;

    for (int i = 0; i < cords.size(); i++) {
        if (x >= cords[i][0] && x <= cords[i][2] && \
            y >= cords[i][1] && y <= cords[i][3])
            res = i;
    }
    cout << res + 1 << endl;
    return 0;
}
