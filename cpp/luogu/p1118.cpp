#include <iostream>
#include <vector>

using namespace std;

bool rls_flag = false;
vector<vector<int>> pc(12, vector<int>(12, 1));

void perm_gen(int n, int total, int len, vector<bool>& visited, vector<int>& t) {
    if (total < 0 || rls_flag) return ;
    if (len == n) {
        if (total == 0) {
            for (const auto& it: t) {
                cout << it << " ";
            }
            cout << endl;
            rls_flag = true;
            return ;
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (visited[i]) continue;
        visited[i] = true;
        t.push_back(i);
        perm_gen(n, total - i * pc[n-1][len], len+1, visited, t);
        visited[i] = false;
        t.pop_back();
    }
}

int main() {
    int n, total; cin >> n >> total;
    for (int i = 2; i <= n-1; ++i) {
        for (int j = 1; j <= i / 2; ++j) {
            pc[i][j] = pc[i-1][j] + pc[i-1][j-1];
            pc[i][i-j] = pc[i][j];
        }
    }
    vector<bool> visited(n+1, false);
    vector<int> t;
    perm_gen(n, total, 0, visited, t);
    return 0;
}