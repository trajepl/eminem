#include <iostream>
#include <string>
#include <queue>

using namespace std;

int graph[1000][1000] = {0};
int visited[1000][1000] = {0};
int mem[1000][1000];
int pos[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int bfs(int i, int j, int n) {
    queue<pair<int, int>> q;
    q.push(make_pair(i, j));
    visited[i][j] = i * n + j + 2;
    while (!q.empty()) {
        pair<int, int> t = q.front(); q.pop();
        for (const auto& p: pos) {
            int new_i = t.first + p[0];
            int new_j = t.second + p[1];
            if (new_i < 0 || new_j < 0 || new_i >= n || new_j >= n) {
                continue;
            }
            if (visited[new_i][new_j] == 0 && (graph[new_i][new_j] ^ graph[t.first][t.second])) {
                q.push(make_pair(new_i, new_j));
                mem[i][j]++;
                visited[new_i][new_j] = i * n + j + 2;
            }
        }
    }
    return mem[i][j];
}

int main() {
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        string t; cin >> t;
        for (int j = 0; j < n; ++j) {
            graph[i][j] = t[j] - '0';
            mem[i][j] = 1;
        }
    }
    pair<int, int> start;
    while (m--) {
        int i, j; cin >> i >> j;
        int v = visited[i-1][j-1];
        if (v >= 2) {
            v -= 2;
            cout << mem[v/n][v%n] << endl;
        } else {
            cout << bfs(i-1, j-1, n) << endl;
        }
    }
    return 0;
}
