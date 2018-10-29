#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int divide(int dividend, int divisor) {
    if (dividend == 0) return 0;
    if (divisor == 0) return -1;
    
    int int_max = pow(2, 31) - 1;
    int int_min = -pow(2, 31);
    long int ret = 0;
    long int ldividend = (long int)dividend;
    long int ldivisor = (long int)divisor;
    bool flag = true;
    if (ldividend < 0) {
        flag = !flag;
        ldividend = -ldividend;
    }
    if (ldivisor < 0) {
        flag = !flag;
        ldivisor = -ldivisor;
    }
    int l = 0;
    while ((ldivisor << l) <= ldividend) l++;
    for (int i = l; i >= 0; --i) {
        if ((ldivisor << i) <= ldividend) {
            ldividend = ldividend - (ldivisor << i);
            ret += (long int)1 << i; 
        } 
    }

    ret = flag ? ret : -ret;
    if (ret > int_max) ret = int_max;
    if (ret < int_min) ret = int_min;
    return ret;
}

int main() {
    cout << divide(-8, 3) << endl;
    return 0;
}
