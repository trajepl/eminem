#include <iostream>
#include <climits>

using namespace std;

int main() {
    int n; cin >> n;
    int t;
    int mem = 0;
    int res = INT_MIN;
    while (n--) {
        cin >> t;
        if (mem + t >= t) {
            mem += t;
        } else {
            mem = t;
        }
        res = max(res, mem);
    }
    cout << res << endl;
    return 0;
}
