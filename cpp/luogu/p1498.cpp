#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

vector<string> paint(int n) {
    if (n == 1) {
        vector<string> rls = {"/\\", "/__\\"};
        return rls;
    }

    vector<string> base = paint(n-1);
    int len = base.size();
    int cnt = (int)(pow(2, n));
    int black_cnt = cnt - 2;
    for (int i = 0; i < len; ++i) {
        string blank_line = "";
        if (black_cnt >= 0) {
            blank_line = string(black_cnt, ' ');
            black_cnt -= 2;
        }
        base.push_back(base[i] + blank_line + base[i]);
    }
    return base;
}


int main() {
    int n; cin >> n;
    vector<string> rls = paint(n);
    int cnt = pow(2, n);
    for (const auto& item: rls) {
        cout << string(--cnt, ' ') << item << endl;
    }
    return 0;
}