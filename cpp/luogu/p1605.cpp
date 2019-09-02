#include <iostream>
#include <unordered_map>

using namespace std;

int graph[6][6] = {0};
int visited[6][6] = {0};
unordered_map<int, int> mem;
pair<int, int> startp, endp;
int res = 0;

int dfs(int i, int j, int n, int m) {
    if (i < 1 || i > n || j < 1 || j > m) return 0;
    if (visited[i][j]) return 0;
    if (graph[i][j] == -1) return 0;
    if (i == endp.first && j == endp.second) {
        return 1;
    }
    visited[i][j] = 1;
    int n1 = dfs(i+1, j, n, m);
    int n2 = dfs(i-1, j, n, m);
    int n3 = dfs(i, j+1, n, m);
    int n4 = dfs(i, j-1, n, m);
    visited[i][j] = 0;
    mem[i*n+j] = n1 + n2 + n3 + n4;
    return mem[i*n+j];
}

int main() {
    int n, m, t; cin >> n >> m >> t;
    cin >> startp.first >> startp.second;
    cin >> endp.first >> endp.second;

    while (t--) {
        int i, j;
        cin >> i >> j;
        graph[i][j] = -1;
    }

    res = dfs(startp.first, startp.second, n, m);
    cout << res << endl;
    return 0;
}
