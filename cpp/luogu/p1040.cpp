#include <iostream>

using namespace std;

int n;
int mem[30][30] = {1};
int root[30][30] = {0};
int scores[30] = {0};

void preorder(int l, int r) {
    if (l > r) return ;
    cout << root[l][r] + 1 << " ";
    preorder(l, root[l][r] - 1);
    preorder(root[l][r] + 1, r);
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> scores[i];
    }
    for (int i = 0; i < n; ++i) {
        mem[i][i] = scores[i];
        root[i][i] = i;
    }

    for (int len = 1; len < n; ++len) {
        for (int i = 0; i + len < n; ++i) {
            int j = i + len;
            mem[i][j] = mem[i+1][j] + mem[i][i];
            root[i][j] = i;

            for (int k = i+1; k <= j; ++k) {
                int val = mem[i][k-1] * mem[k+1][j] + mem[k][k];
                if (val > mem[i][j]) {
                    mem[i][j] = val;
                    root[i][j] = k;
                }
            }
        }
    }

    cout << mem[0][n-1] << endl;
    preorder(0, n-1);
    cout << endl;
    return 0;
}
