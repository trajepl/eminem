#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int total = 0;
int k = 3;
int a[100], b[100], k1[100], k2[100];

void dfs(int n, int row) {
    if (row == n) {
        total++;
        if (k == 0) return ;
        for (int i = 0; i < n; ++i) {
            cout << a[i]+1 << " ";
        }
        cout << endl;
        k--;
        return ;
    }
    if (row == n) return ;
    for (int i = 0; i < n; ++i) {
        if ((!b[i]) && (!k1[row+i]) && (!k2[row-i+n])) {
            a[row] = i;
            b[i] = 1;
            k1[row+i] = 1;
            k2[row-i+n] = 1;
            dfs(n, row+1);
            a[row] = -1;
            b[i] = 0;
            k1[row+i] = 0;
            k2[row-i+n] = 0;
        }
    } 
    return ;
}

int main() {
    int n; cin >> n;
    dfs(n, 0);
    cout << total << endl;
    return 0;
}
