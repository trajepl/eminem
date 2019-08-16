#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n; cin >> n;
    for (int i = n; i >= 0; --i) {
        int a; cin >> a;
        if (a > 0) {
            if (i != n) cout << "+";
            if (a != 1) cout << a;
        } else if (a < 0) {
            if (a != -1) cout << a;
            else if (a == -1 && i != 0) cout << "-";
        }
        if (a != 0) {
            if (i != 0) cout << "x";
            if (i >= 2) cout << "^" << i;
            if (abs(a) == 1 && i == 0) cout << a;
        }
    }
    cout << endl;
    return 0;
}
