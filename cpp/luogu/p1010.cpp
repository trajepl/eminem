#include <iostream>
#include <string>

using namespace std;

string format(int n) {
    string rls = "";
    int idx = 0;
    while (n > 0) {
        if (n & 1) {
            if (idx > 1) {
                rls = "2(" + format(idx) + ")+" + rls;
            } else if (idx == 1) {
                rls = "2+" + rls;
            } else if (idx == 0) {
                rls = "2(0)+" + rls;
            }
        }
        n >>= 1;
        ++idx;
    }
    return rls.substr(0, rls.size()-1);
}

int main() {
    int n; cin >> n;
    cout << format(n) << endl;
    return 0;
}