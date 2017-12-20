#include <iostream>
#include <vector>
using namespace std;

int knap(int m, vector<int> &p, vector<int> &w) {
    vector<int> dp(m+1, 0);
    for (int i = 0; i < p.size(); i++) {
        for (int j = m; j >= w[i]; j--)
            dp[j] = max(dp[j], dp[j-w[i]] + p[i]);
    }
    return dp[m];
}

void run(int m, vector<int> &p, vector<int> &w) {
    cout << "M = " << m << endl;
    cout << "P = ";
    for (auto pi: p)
        cout << pi << " ";
    cout << "\n";
    cout << "W = ";
    for (auto wi: w)
        cout << wi << " ";
    cout << "\n";
    cout << "max value = " << knap(m, p, w) << endl;
    return;
}

int main() {
    int m;
    vector<int> p, w;

    m = 6;
    p = {1, 2, 5}, w = {2, 3, 4};
    run(m, p, w);

    cout << endl;

    m = 10;
    p = {4, 6, 7}, w = {3, 4, 5};
    run(m, p, w);

    cout << endl;

    m = 30;
    p = {2, 5, 8, 1}, w = {10, 15, 6, 9};
    run(m, p, w);
    return 0;
}
