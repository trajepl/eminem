#include <iostream>
#include <vector>

using namespace std;

void update(vector<vector<int>> &info, int t) {
    for (int i = 0; i < info.size(); i++) {
        info[i][0] = (info[i][2] * t + info[i][0] > info[i][1]) ? info[i][1]: info[i][2] * t + info[i][0];
    }
}

int draw(vector<vector<int>> &info, int l, int r) {
    int sum = 0;
    for (int i = l; i <= r; i++) {
        sum += info[i][0];
        info[i][0] = 0;
    }
    return sum;
}

int run(vector<vector<int>> info, vector<vector<int>> state) {
    int cnt = state.size();
    int ret = 0;
    
    for (int i = 1; i < cnt; i++) {
        update(info, state[i][0] - state[i - 1][0]);
        ret += draw(info, state[i][1], state[i][2]);
    }
    return ret;
}

int main() {
    int n; cin >> n;
    vector<vector<int>> info;
    while (n-- > 0) {
        int s, m, r;
        cin >> s >> m >> r;
        info.push_back({s, m , r});
    }

    int m; cin >> m;
    vector<vector<int>> state = {{0, 0, 0}};
    while (m-- > 0) {
        int t, l, r;
        cin >> t >> l >> r;
        state.push_back({t, l-1, r-1});
    }
    cout << run(info, state) << endl;
    return 0;
}
