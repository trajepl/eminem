#include <iostream>
#include <string>

using namespace std;

int main() {
    int n; cin >> n;
    string res = "";
    int res_idx = 0;
    for (int i = 1; i <= n; ++i) {
        string t; cin >> t;
        if (res == "") res = t;
        else {
            if (res.length() < t.length()) {
                res = t;
                res_idx = i;
            } else if (res.length() == t.length()) {
                if (res < t) {
                    res = t;
                    res_idx = i;
                }
            }
        }
    }
    cout << res_idx << endl;
    cout << res << endl;
    return 0;
}
