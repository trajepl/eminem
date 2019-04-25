#include <iostream>
#include <string>

using namespace std;

int main() {
    int n; cin >> n;
    string s; cin >> s;
    bool res = false;
    int l, r;
    for (int i = 1; i < s.size(); ++i) {
        if (s[i] < s[i-1]) {
            res = true;
            l = i;
            r = i + 1;
            break;
        }
    }
    if (res) cout << "YES" << endl << l << " " << r << endl;
    else cout << "NO" << endl;
    return 0;
}
