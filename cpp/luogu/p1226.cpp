#include <iostream>

using namespace std;

int main() {
    long long int b, p, k; cin >> b >> p >> k;
    long long int tp = p;
    long long int tb = b;
    long long int rls = 1;
    while (p > 0) {
        if (p & 1) {
            rls *= b;
            rls %= k;
        }
        b *= b;
        b %= k;
        p >>= 1;
    }
    rls %= k;
    cout << tb << "^" << tp << " mod " << k << "=" << rls << endl;
    return 0;
}