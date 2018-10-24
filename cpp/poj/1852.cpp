#include <iostream>
#include <vector>

using namespace std;

int main() {
    int l, n, loop;
    cin >> loop;
    while (loop--) {
        cin >> l >> n;
        int minT = 0, maxT = 0;
        while (n--) {
            int t; cin >> t;
            minT = max(minT, min(t, l-t));
            maxT = max(maxT, max(t, l-t));
        }
        cout << minT << " " << maxT << endl;
    }
    return 0;
}
