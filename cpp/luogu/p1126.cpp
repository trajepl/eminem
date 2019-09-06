#include <iostream>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;

int graph[51][51] = {0};
int reset_p[4][2] = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};
int pos[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int mem[51][51][4] = {0};
queue<vector<int>> q;
pair<int, int> start_p, end_p;

void bfs(int idx, int n, int m) {
    q.push({start_p.first, start_p.second, 0, idx});
    mem[start_p.first][start_p.second][idx] = 1;
    while (!q.empty()) {
        vector<int> t = q.front(); q.pop();

        if (t[0] == end_p.first && t[1] == end_p.second) {
            cout << t[2] << endl;
            return ;
        }
        
        for (int k = 0; k < 4; ++k) {
            if (abs(pos[k][0] - pos[t[3]][0]) == 2 \
                || abs(pos[k][1] - pos[t[3]][1]) == 2) {
                continue;
            }
            int i = t[0];
            int j = t[1];
            if (k == t[3]) {
                for (int x = 0; x < 3; ++x) {
                    i += pos[k][0];
                    j += pos[k][1];
                    if (i <= 0 || j <= 0 || i > n-1 || j > m-1) {
                        break;
                    }
                    if (graph[i][j] != 1) {
                        if (mem[i][j][k] > 0) continue;
                        q.push({i, j, t[2]+1, k});
                        mem[i][j][k] = 1;
                    } else {
                        break;
                    }
                }
            } else {
                if (mem[t[0]][t[1]][k] > 0) continue;
                q.push({t[0], t[1], t[2]+1, k});
                mem[t[0]][t[1]][k] = 1;
            }
        }
    }
    cout << -1 << endl;
}

int main() {
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int t; cin >> t;
            if (t == 1) {
                for (const auto& p: reset_p) {
                    int new_i = i + p[0];
                    int new_j = j + p[1];
                    graph[new_i][new_j] = 1;
                }
            }
        }
    }

    cin >> start_p.first >> start_p.second;
    cin >> end_p.first >> end_p.second;
    if (graph[end_p.first][end_p.second] == 1) {
        cout << -1 << endl;
        return 0;
    }

    char c; cin >> c;
    int dir = 0;
    switch(c) {
        case 'N': dir = 3; break;
        case 'S': dir = 2; break;
        case 'W': dir = 1; break;
        case 'E': dir = 0; break;
    }
    bfs(dir, n, m);
    return 0;
}
